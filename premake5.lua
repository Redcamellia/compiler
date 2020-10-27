workspace "Lexical"
    architecture "x64"

    configurations
    {
        "Debug" ,
        "Release"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



project "Lexical"
location "Lexical"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/source/**.h",
		"%{prj.name}/source/**.cpp"
    }
    filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"



filter "configurations:Debug"
    symbols "On"

filter "configurations:Release"
    optimize "On"