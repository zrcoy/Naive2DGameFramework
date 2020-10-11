workspace "Tiny2DGameEngine"
	architecture "x86"

	configurations {"Debug", "Release" }

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Tiny2DGameEngine"
	location "Tiny2DGameEngine"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/assets/**"
	}

	includedirs
	{
		"Libraries/glm/include",
		"Libraries/lua-5.3.5_Win32_dllw6_lib/include",
		"Libraries/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/include",
		"Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/include",
		"Libraries/SDL2_ttf-devel-2.0.15-VC/SDL2_ttf-2.0.15/include",
		"Libraries/SDL2-devel-2.0.10-VC/SDL2-2.0.10/include"
	}

	libdirs
	{
		"Libraries/lua-5.3.5_Win32_dllw6_lib",
		"Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86",
		"Libraries/SDL2_ttf-devel-2.0.15-VC/SDL2_ttf-2.0.15/lib/x86",
		"Libraries/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/lib/x86",
		"Libraries/SDL2-devel-2.0.10-VC/SDL2-2.0.10/lib/x86"
	}

	links
	{
		"SDL2_mixer",
		"SDL2_ttf",
		"SDL2_image",
		"SDL2",
		"SDL2main"
	}
	
	postbuildcommands
	{
		("{COPY} %{wks.location}/Libraries/lua-5.3.5_Win32_dllw6_lib/lua53.dll %{wks.location}/bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/lib/x86/SDL2_image.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/lib/x86/libjpeg-9.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/lib/x86/libpng16-16.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/lib/x86/libtiff-5.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/lib/x86/libwebp-7.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86/SDL2_mixer.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86/libFLAC-8.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86/libmodplug-1.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86/libmpg123-0.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86/libogg-0.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86/libopus-0.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86/libopusfile-0.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86/libvorbis-0.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_mixer-devel-2.0.4-VC/SDL2_mixer-2.0.4/lib/x86/libvorbisfile-3.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_ttf-devel-2.0.15-VC/SDL2_ttf-2.0.15/lib/x86/SDL2_ttf.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_ttf-devel-2.0.15-VC/SDL2_ttf-2.0.15/lib/x86/libfreetype-6.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2_ttf-devel-2.0.15-VC/SDL2_ttf-2.0.15/lib/x86/zlib1.dll ../bin/" .. outputdir .."/%{prj.name}"),
		("{COPY} %{wks.location}/Libraries/SDL2-devel-2.0.10-VC/SDL2-2.0.10/lib/x86/SDL2.dll ../bin/" .. outputdir .."/%{prj.name}"),
	
		
	}
	

	filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"


        filter "configurations:Debug"
            symbols "On"

        filter "configurations:Release"
            optimize "On"

        filter "configurations:Dist"
            optimize "On"

		