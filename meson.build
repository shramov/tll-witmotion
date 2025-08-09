project('tll-witmotion', 'cpp'
	, version: '0.0.0'
	, license: 'MIT'
	, default_options: ['cpp_std=c++17', 'werror=true', 'optimization=2']
)

include = [include_directories('src')]

fmt = dependency('fmt')
tll = dependency('tll')

shared_library('tll-witmotion'
	, ['src/channel.cc']
	, include_directories : include
	, dependencies : [fmt, tll]
	, install : true
)
