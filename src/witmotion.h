#pragma once

#include <tll/scheme/binder.h>
#include <tll/util/conv.h>

namespace witmotion {

static constexpr std::string_view scheme_string = R"(yamls+gz://eJyt0j0LgzAQgOG9v+K2LBX6AUXcCq5upeAY4rUGkigxNk1L/3sVqoIit3S74eHyciQCwzUmwC5SI9sAyCKBeNcNN4mqaJJuAojg/WN5zrbgQt3PrTQuZp+ZyDJKpCklypISWlOiacgdM7E/dSQaDnIWAhVa7mRlxsPsVw/Dn9OyYddMBFK8KOFQ131Ta3FJp3RzbxW3V1SVkC6M9YfVek/We7Le/69eTV/xuNpsK6WoF2vpREmhwD1FHmib/h8s/8sXWsjsZA==)";

struct Time
{
	static constexpr size_t meta_size() { return 8; }
	static constexpr std::string_view meta_name() { return "Time"; }
	static constexpr int meta_id() { return 80; }

	template <typename Buf>
	struct binder_type : public tll::scheme::Binder<Buf>
	{
		using tll::scheme::Binder<Buf>::Binder;

		static constexpr auto meta_size() { return Time::meta_size(); }
		static constexpr auto meta_name() { return Time::meta_name(); }
		static constexpr auto meta_id() { return Time::meta_id(); }
		void view_resize() { this->_view_resize(meta_size()); }

		using type_YY = uint8_t;
		type_YY get_YY() const { return this->template _get_scalar<type_YY>(0); }
		void set_YY(type_YY v) { return this->template _set_scalar<type_YY>(0, v); }

		using type_MM = uint8_t;
		type_MM get_MM() const { return this->template _get_scalar<type_MM>(1); }
		void set_MM(type_MM v) { return this->template _set_scalar<type_MM>(1, v); }

		using type_DD = uint8_t;
		type_DD get_DD() const { return this->template _get_scalar<type_DD>(2); }
		void set_DD(type_DD v) { return this->template _set_scalar<type_DD>(2, v); }

		using type_hh = uint8_t;
		type_hh get_hh() const { return this->template _get_scalar<type_hh>(3); }
		void set_hh(type_hh v) { return this->template _set_scalar<type_hh>(3, v); }

		using type_mm = uint8_t;
		type_mm get_mm() const { return this->template _get_scalar<type_mm>(4); }
		void set_mm(type_mm v) { return this->template _set_scalar<type_mm>(4, v); }

		using type_ss = uint8_t;
		type_ss get_ss() const { return this->template _get_scalar<type_ss>(5); }
		void set_ss(type_ss v) { return this->template _set_scalar<type_ss>(5, v); }

		using type_ms = uint16_t;
		type_ms get_ms() const { return this->template _get_scalar<type_ms>(6); }
		void set_ms(type_ms v) { return this->template _set_scalar<type_ms>(6, v); }
	};

	template <typename Buf>
	static binder_type<Buf> bind(Buf &buf, size_t offset = 0) { return binder_type<Buf>(tll::make_view(buf).view(offset)); }
};

struct Acceleration
{
	static constexpr size_t meta_size() { return 8; }
	static constexpr std::string_view meta_name() { return "Acceleration"; }
	static constexpr int meta_id() { return 81; }

	template <typename Buf>
	struct binder_type : public tll::scheme::Binder<Buf>
	{
		using tll::scheme::Binder<Buf>::Binder;

		static constexpr auto meta_size() { return Acceleration::meta_size(); }
		static constexpr auto meta_name() { return Acceleration::meta_name(); }
		static constexpr auto meta_id() { return Acceleration::meta_id(); }
		void view_resize() { this->_view_resize(meta_size()); }

		using type_ax = int16_t;
		type_ax get_ax() const { return this->template _get_scalar<type_ax>(0); }
		void set_ax(type_ax v) { return this->template _set_scalar<type_ax>(0, v); }

		using type_ay = int16_t;
		type_ay get_ay() const { return this->template _get_scalar<type_ay>(2); }
		void set_ay(type_ay v) { return this->template _set_scalar<type_ay>(2, v); }

		using type_az = int16_t;
		type_az get_az() const { return this->template _get_scalar<type_az>(4); }
		void set_az(type_az v) { return this->template _set_scalar<type_az>(4, v); }

		using type_temperature = int16_t;
		type_temperature get_temperature() const { return this->template _get_scalar<type_temperature>(6); }
		void set_temperature(type_temperature v) { return this->template _set_scalar<type_temperature>(6, v); }
	};

	template <typename Buf>
	static binder_type<Buf> bind(Buf &buf, size_t offset = 0) { return binder_type<Buf>(tll::make_view(buf).view(offset)); }
};

struct AngularVelocity
{
	static constexpr size_t meta_size() { return 8; }
	static constexpr std::string_view meta_name() { return "AngularVelocity"; }
	static constexpr int meta_id() { return 82; }

	template <typename Buf>
	struct binder_type : public tll::scheme::Binder<Buf>
	{
		using tll::scheme::Binder<Buf>::Binder;

		static constexpr auto meta_size() { return AngularVelocity::meta_size(); }
		static constexpr auto meta_name() { return AngularVelocity::meta_name(); }
		static constexpr auto meta_id() { return AngularVelocity::meta_id(); }
		void view_resize() { this->_view_resize(meta_size()); }

		using type_wx = int16_t;
		type_wx get_wx() const { return this->template _get_scalar<type_wx>(0); }
		void set_wx(type_wx v) { return this->template _set_scalar<type_wx>(0, v); }

		using type_wy = int16_t;
		type_wy get_wy() const { return this->template _get_scalar<type_wy>(2); }
		void set_wy(type_wy v) { return this->template _set_scalar<type_wy>(2, v); }

		using type_wz = int16_t;
		type_wz get_wz() const { return this->template _get_scalar<type_wz>(4); }
		void set_wz(type_wz v) { return this->template _set_scalar<type_wz>(4, v); }

		using type_temperature = int16_t;
		type_temperature get_temperature() const { return this->template _get_scalar<type_temperature>(6); }
		void set_temperature(type_temperature v) { return this->template _set_scalar<type_temperature>(6, v); }
	};

	template <typename Buf>
	static binder_type<Buf> bind(Buf &buf, size_t offset = 0) { return binder_type<Buf>(tll::make_view(buf).view(offset)); }
};

struct Angle
{
	static constexpr size_t meta_size() { return 8; }
	static constexpr std::string_view meta_name() { return "Angle"; }
	static constexpr int meta_id() { return 83; }

	template <typename Buf>
	struct binder_type : public tll::scheme::Binder<Buf>
	{
		using tll::scheme::Binder<Buf>::Binder;

		static constexpr auto meta_size() { return Angle::meta_size(); }
		static constexpr auto meta_name() { return Angle::meta_name(); }
		static constexpr auto meta_id() { return Angle::meta_id(); }
		void view_resize() { this->_view_resize(meta_size()); }

		using type_roll = int16_t;
		type_roll get_roll() const { return this->template _get_scalar<type_roll>(0); }
		void set_roll(type_roll v) { return this->template _set_scalar<type_roll>(0, v); }

		using type_pitch = int16_t;
		type_pitch get_pitch() const { return this->template _get_scalar<type_pitch>(2); }
		void set_pitch(type_pitch v) { return this->template _set_scalar<type_pitch>(2, v); }

		using type_yaw = int16_t;
		type_yaw get_yaw() const { return this->template _get_scalar<type_yaw>(4); }
		void set_yaw(type_yaw v) { return this->template _set_scalar<type_yaw>(4, v); }

		using type_version = uint16_t;
		type_version get_version() const { return this->template _get_scalar<type_version>(6); }
		void set_version(type_version v) { return this->template _set_scalar<type_version>(6, v); }
	};

	template <typename Buf>
	static binder_type<Buf> bind(Buf &buf, size_t offset = 0) { return binder_type<Buf>(tll::make_view(buf).view(offset)); }
};

} // namespace witmotion
