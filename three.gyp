{
	'targets': [
		{
			'target_name': 'libthree',
			'type': '<(library)',
			'include_dirs': [
				'include'
			],
			'sources': [
				'src/internal.h',
				'src/matrix.c',
				'src/vector.c',
				'common.gypi',
			],
			'libraries': [
				'$(SDKROOT)/System/Library/Frameworks/OpenGL.framework',
			],
			'direct_dependent_settings': {
				'include_dirs': [
					'include'
				],
				'libraries': [
					'$(SDKROOT)/System/Library/Frameworks/OpenGL.framework',
				],
			}
		},

		{
			'target_name': 'run-tests',
			'type': 'executable',
			'dependencies': [
				'libthree',
				'deps/glfw/glfw.gyp:glfw',
			],
			'sources': [
				'test/tests.h',
				'test/tests.c',
			],
		},
	]
}