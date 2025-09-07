workspace "Kulo"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }
    
local outputdir = "%{cfg.buildcfg}-%{cfg.system}-{cfg.architecture}"

project "Kulo"
    location "Kulo"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "KL_PLATFORM_WIN",
            "KL_BUILD_DLL"
        }

        postbuildcommands 
        {
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines "KL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "KL_DIST"
        optimize "On"

    filter {}


project "Sandbox"
    location "Sandbox"
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
        "Kulo/vendor/spdlog/include",
        "Kulo/src"
    }

    links 
    {
        "Kulo"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "KL_PLATFORM_WIN"
        }
        
        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines "KL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "KL_DIST"
        optimize "On"

