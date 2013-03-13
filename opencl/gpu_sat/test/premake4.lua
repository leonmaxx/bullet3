function createProject(vendor)	
	hasCL = findOpenCL(vendor)
	
	if (hasCL) then

		project ("OpenCL_sat_test_" .. vendor)

		initOpenCL(vendor)

		language "C++"
				
		kind "ConsoleApp"
		targetdir "../../../bin"
		includedirs {"..","../.."}
		
		
		files {
			"main.cpp",
			"../../basic_initialize/btOpenCLInclude.h",
			"../../basic_initialize/btOpenCLUtils.cpp",
			"../../basic_initialize/btOpenCLUtils.h",
			"../host/ConvexHullContact.cpp",
			"../host/ConvexHullContact.h",
			"../../parallel_primitives/host/btFillCL.cpp",
			"../../parallel_primitives/host/btFillCL.h",
			"../../parallel_primitives/host/btBoundSearchCL.cpp",
			"../../parallel_primitives/host/btBoundSearchCL.h",
			"../../parallel_primitives/host/btPrefixScanCL.cpp",
			"../../parallel_primitives/host/btPrefixScanCL.h",
			"../../parallel_primitives/host/btRadixSort32CL.cpp",
			"../../parallel_primitives/host/btRadixSort32CL.h",
			"../../parallel_primitives/host/btAlignedAllocator.cpp",
			"../../parallel_primitives/host/btAlignedAllocator.h",
			"../../parallel_primitives/host/btAlignedObjectArray.h",
			"../../parallel_primitives/host/btQuickprof.cpp",
			"../../parallel_primitives/host/btQuickprof.h",

		}
		
	end
end

createProject("AMD")
createProject("Intel")
createProject("NVIDIA")
createProject("Apple")