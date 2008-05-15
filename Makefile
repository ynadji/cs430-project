all:
	gcc project.c -o project
	sbcl --noinform --eval "(progn (compile-file \"project.lisp\") (quit))"
	javac sorts/Sorts.java
	javac sorts/Test.java

run: c lisp ruby java

c:
	./project

ruby:
	ruby sorts.rb

java:
	java sorts.Test

lisp:
	sbcl --noinform --load project.fasl --eval "(progn (cs430-project:run-all-tests) (quit))"

clean:
	rm -f project project.fasl sorts/*.class
