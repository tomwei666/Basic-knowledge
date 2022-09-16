name1:=abc
name2=abc def
a: a.c
	gcc -o a a.c
b: b.c
	gcc -o b b.c
	@echo "name1=" ${name1} "name2=" ${name2}
	@echo "filter-out="$(filter-out ${name1}, ${name2})
	@echo "name1=" ${name1} "name2=" ${name2}
	@echo "filter=" $(filter ${name1}, ${name2})
	@echo "name1=" ${name1} "name2=" ${name2}
