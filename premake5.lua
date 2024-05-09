if _ACTION ~= 'vs2022' and _ACTION ~= 'info' then
    print('This project needs to be compiled for VisualStudio 2022')
    os.exit()
end

local ProjectName = 'Discord++'

local SOLUTION_DIR
local PLATFORM_TARGET
local CONFIGURATION
local BUILD_PATH
local INTERMEDIATE_PATH

if os.host() == 'windows' then
    SOLUTION_DIR = '$(SolutionDir)'
    PLATFORM_TARGET = '$(PlatformTarget)'
    CONFIGURATION = '$(Configuration)'
else
    SOLUTION_DIR = path.getabsolute('.')..'/'
    PLATFORM_TARGET = '%{cfg.platform}'
    CONFIGURATION = '%{cfg.buildcfg}'
end

BUILD_PATH = ('%sBuild/%s/%s/'):format(SOLUTION_DIR, PLATFORM_TARGET, CONFIGURATION)
INTERMEDIATE_PATH = ('!%sIntermediate/%s/%s/'):format(SOLUTION_DIR, PLATFORM_TARGET, CONFIGURATION)


if _ACTION == 'info' then
    print('ProjectName:        '..ProjectName)
    print('--------------------------------------')
    print('SOLUTION_DIR:       '..SOLUTION_DIR)
    print('PLATFORM_TARGET:    '..PLATFORM_TARGET)
    print('CONFIGURATION:      '..CONFIGURATION)
    print('BUILD_PATH:         '..BUILD_PATH)
    print('INTERMEDIATE_PATH: ' ..INTERMEDIATE_PATH)
    print('--------------------------------------')

    os.exit()
end

workspace ( ProjectName )
	configurations { 'Debug', 'Release' }
    platforms { 'x86', 'x64' }

    project ( ProjectName )
        kind 'ConsoleApp'
        cppdialect 'C++latest'
        cdialect 'C17'
        language 'C++'

        vpaths {
            ['Headers/*'] = { 'hpp/**.hpp' },
            ['HeadersLib/*'] = { 'include/**.hpp', 'include/**.h' },
            ['Sources/*'] = { 'src/**.cpp' },
            ['*'] = 'premake5.lua'
        }

        files {
            'src/**.cpp',
            'hpp/**.hpp',
            'include/**.h',
            'include/**.hpp',
        }

        includedirs {
            SOLUTION_DIR..'hpp',
            SOLUTION_DIR..'include'
        }

        targetdir (BUILD_PATH)
        objdir (INTERMEDIATE_PATH)

        staticruntime 'on'
        flags {
            'MultiProcessorCompile',
        }

        filter {}
            defines { 'CURL_STATICLIB' }
            links { 'libcrypto', 'libssl' }

        filter 'platforms:x86'
            libdirs { 'lib/x86' }

        filter 'platforms:x64'
            libdirs { 'lib/x64' }

        filter 'configurations:Debug'
            defines { '_DEBUG' }
            symbols 'On'
            optimize 'Off'
            runtime 'Debug'
            functionlevellinking 'On'
            links { 'libcurl_d', 'zlib_d' }

        filter 'configurations:Release'
            defines { 'NDEBUG' }
            symbols 'Off'
            optimize 'Full'
            runtime 'Release'
            functionlevellinking 'On'
            links { 'libcurl', 'zlib' }

            flags {
                'LinkTimeOptimization',
                'NoIncrementalLink'
            }

	    filter 'system:windows'
            defines {
                '_WIN32', 'WIN32_LEAN_AND_MEAN',
                'NOGDICAPMASKS', 'NOVIRTUALKEYCODES', 'NOWINMESSAGES', 'NOWINSTYLES',
                'NOSYSMETRICS', 'NOMENUS', 'NOICONS', 'NOKEYSTATES', 'NOSYSCOMMANDS',
                'NORASTEROPS', 'NOSHOWWINDOW', 'OEMRESOURCE', 'NOATOM', 'NOCLIPBOARD',
                'NOCOLOR', 'NOCTLMGR', 'NODRAWTEXT', 'NOGDI', 'NOKERNEL', 'NOUSER',
                'NONLS', 'NOMB', 'NOMEMMGR', 'NOMETAFILE', 'NOMINMAX', 'NOMSG',
                'NOOPENFILE', 'NOSCROLL', 'NOSERVICE', 'NOSOUND', 'NOTEXTMETRIC',
                'NOWH', 'NOWINOFFSETS', 'NOCOMM', 'NOKANJI', 'NOHELP', 'NOPROFILER',
                'NODEFERWINDOWPOS', 'NOMCX', 'NOIME'
            }
            links { 'ws2_32', 'crypt32' }
        