1. $(findstring <find>,<in>)
名称: 查找字符串函数--findstring. 功能:在字串<in>中查找<find>字串。
如果找到，那么返回<find>,否则返回空字符串。

2.  foreach
   $(foreach <var>,<list>,<text>)
	这个函数的意思是，把参数<list>;中的单词逐一取出放到参数<var>;所指定的变量中，然后再执行< text>;所包含的表达式。
	每一次<text>;会返回一个字符串，循环过程中，<text>;的所返回的每个字符串会以空格分隔，最后当整个循环结束时，<text>;
	所返回的每个字符串所组成的整个字符串（以空格分隔）将会是foreach函数的返回值。

	names :=a b c d
	files:=$(foreach n,$(names),$(n).o)
	所以$(files)的值是"a.o b.o c.o d.o"
3. 执行结果:
export SD_BUILD_LK_SSYSTEM_NAME=ssystem_x9_plus_ref_serdes
tom@tom-linuxer:~/work1/github-tom/Basic-knowledge/Makefile/04-foreach-findstring$ make all
a

SD_BUILD_LK_SSYSTEM_NAME
