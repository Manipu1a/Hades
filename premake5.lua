workspace "Hades"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project "Hades"
	location "Hades"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HADES_PLATFORM_WINDOWS",
			"HADES_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
		}

	filter "configurations:Debug"
		defines "HADES_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HADES_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HADES_DIST"
		optimize "On"


project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hades/vendor/spdlog/include",
		"Hades/src"
	}

	links
	{
		"Hades"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HADES_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HADES_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HADES_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HADES_DIST"
		optimize "On"

