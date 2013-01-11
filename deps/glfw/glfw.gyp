{
  'targets': [
    {
      'target_name': 'glfw',
      'type': 'static_library',
      'include_dirs': [
        'include',
        'include/GL',
        'lib'
      ],
      'direct_dependent_settings': {
        'include_dirs': [ 'include' ],
        'libraries': [
	        '$(SDKROOT)/System/Library/Frameworks/OpenGL.framework',
	        '$(SDKROOT)/System/Library/Frameworks/Cocoa.framework',
	        '$(SDKROOT)/System/Library/Frameworks/IOKit.framework',
      	]
      },
      'sources': [
        'include/GL/glfw.h',
        'lib/enable.c',
        'lib/fullscreen.c',
        'lib/glext.c',
        'lib/image.c',
        'lib/init.c',
        'lib/input.c',
        'lib/internal.h',
        'lib/joystick.c',
        'lib/stream.c',
        'lib/tga.c',
        'lib/thread.c',
        'lib/time.c',
        'lib/window.c',
      ],
      'conditions': [
        [ 'OS=="win"', {
          'sources': [
            'lib/win32/',
          ]},
        ],
        [ 'OS=="mac"', {
          'include_dirs': [
	        'lib/cocoa'
	      ],
	      'cflags': [
	      	'-O2',
	      	'-g',
			'-c',
			'-Wall'
		  ],
          'sources': [
          	'lib/cocoa/cocoa_enable.m',
          	'lib/cocoa/cocoa_fullscreen.m',
          	'lib/cocoa/cocoa_glext.m',
          	'lib/cocoa/cocoa_init.m',
          	'lib/cocoa/cocoa_joystick.m',
          	'lib/cocoa/cocoa_thread.c',
          	'lib/cocoa/cocoa_time.m',
          	'lib/cocoa/cocoa_window.m',
          	'lib/cocoa/platform.h'
          ],
          'libraries': [
		    '$(SDKROOT)/System/Library/Frameworks/OpenGL.framework',
		    '$(SDKROOT)/System/Library/Frameworks/Cocoa.framework',
		    '$(SDKROOT)/System/Library/Frameworks/IOKit.framework',
		  ]
        }],
        [ 'OS=="linux"', {
          'include_dirs': [
	        'lib/x11'
	      ],
          'sources': [
            'lib/x11'
          ],
          'defines': [
            'EV_CONFIG_H="config_linux.h"',
            'EIO_CONFIG_H="config_linux.h"',
          ],
          'direct_dependent_settings': {
            'libraries': [ '-lrt' ],
          },
        }]
      ]
    }
  ]
}