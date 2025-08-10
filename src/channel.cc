// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Pavel Shramov <shramov@mexmat.net>

#include <tll/channel/module.h>
#include <tll/channel/prefix.h>
#include <tll/channel/tcp.h>

#include "witmotion.h"

using namespace tll::channel;

struct __attribute__((packed)) Packet
{
	uint8_t marker;
	uint8_t msgid;
	uint8_t body[8];
	uint8_t checksum;
};

class WitMotion : public Prefix<WitMotion>
{
	using Base = Prefix<WitMotion>;

	PartialBuffer _buf;

 public:
	static constexpr std::string_view channel_protocol() { return "witmotion+"; }
	static constexpr auto process_policy() { return Base::ProcessPolicy::Normal; }

	const tll::Scheme * scheme(int type) const
	{
		if (type == TLL_MESSAGE_DATA)
			return _scheme.get();
		return Base::scheme(type);
	}

	int _on_active()
	{
		_buf.resize(1024);
		_scheme.reset(context().scheme_load(witmotion::scheme_string));
		if (!_scheme)
			return _log.fail(EINVAL, "Failed to load WitMotion scheme");
		return 0;
	}

	int _on_data(const tll_msg_t *msg);
	int _process(long timeout, int flags);

	size_t _next() const;
};

int WitMotion::_on_data(const tll_msg_t *msg)
{
	if (_buf.available() < msg->size) {
		_log.warning("Skip {} bytes of data", msg->size);
		return 0;
	}

	memcpy(_buf.end(), msg->data, msg->size);
	_buf.extend(msg->size);
	_process(0, 0);
	return 0;
}

size_t WitMotion::_next() const
{
	auto view = tll::make_view(_buf);
	for (; view.size() >= 11; view = view.view(1)) {
		auto msg = view.dataT<Packet>();
		if (msg->marker != 0x55)
			continue;

		uint8_t checksum = msg->marker + msg->msgid;
		for (auto i : msg->body)
			checksum += i;
		if (checksum != msg->checksum) {
			_log.debug("Checksum mismatch: {} != data {}", checksum, msg->checksum);
			continue;
		}
		break;
	}
	return view.offset();
}

int WitMotion::_process(long timeout, int flags)
{
	auto offset = _next();
	auto view = tll::make_view(_buf, offset);
	if (view.size() < 11) {
		if (offset) { // XXX: Guard until fixed in tll
			_log.trace("Skip {} bytes of invalid data", offset);
			_buf.done(offset);
			_buf.shift();
		}
		_dcaps_pending(false);
		return EAGAIN;
	}

	auto data = *view.dataT<Packet>(); // Copy
	_buf.done(sizeof(data));
	_buf.shift();
	_dcaps_pending(_buf.size());

	if (data.msgid < 0x50 || data.msgid > 0x53)
		return 0;

	tll_msg_t msg = {};
	msg.msgid = data.msgid;
	msg.size = sizeof(data.body);
	msg.data = &data.body;
	_callback_data(&msg);
	return 0;
}

TLL_DEFINE_IMPL(WitMotion);

TLL_DEFINE_MODULE(WitMotion);
