file(REMOVE_RECURSE
  "123.exe"
  "123.exe.manifest"
  "123.pdb"
  "CMakeFiles/123.dir/123.cpp.obj"
  "lib123.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/123.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
