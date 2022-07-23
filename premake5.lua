workspace "Hades"
	startproject "Game"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

IncludeDir = {}
IncludeDir["GLFW"] = "Hades/vendor/GLFW/include"
IncludeDir["Glad"] = "Hades/vendor/Glad/include"
IncludeDir["imgui"] = "Hades/vendor/imgui"
IncludeDir["glm"] = "Hades/vendor/glm"

include "Hades/vendor/GLFW"
include "Hades/vendor/Glad"
include "Hades/vendor/imgui"

project "Hades"
	location "Hades"
	kind "SharedLib"
	staticruntime "off"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hdpch.h"
	pchsource "Hades/src/hdpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Glad",
		"GLFW",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"HADES_PLATFORM_WINDOWS",
			"HADES_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Game/\"")
		}

	filter "configurations:Debug"
		defines "HADES_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HADES_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HADES_DIST"
		runtime "Release"
		optimize "On"

project "Game"
	location "Game"
	kind "ConsoleApp"
	staticruntime "off"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",

	}

	includedirs
	{
		"Hades/vendor/spdlog/include",
		"Hades/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Hades"
	}
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"HADES_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HADES_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HADES_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HADES_DIST"
		runtime "Release"
		optimize "On"

