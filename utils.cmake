
# Shortcut to define list of source files.
macro(mklist dest root)
	file(RELATIVE_PATH _here
			"${root}" "${CMAKE_CURRENT_SOURCE_DIR}")
	foreach(e ${ARGN})
		list(APPEND ${dest} "${_here}/${e}")
	endforeach(e)
	#message("mklist ${dest} = ${${dest}}")
endmacro(mklist)

