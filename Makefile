all:
	gcc project.c -o project
	sbcl --noinform --eval "(progn (compile-file \"project.lisp\") (quit))"

run: c lisp

c:
	./project

lisp:
	sbcl --noinform --load project.fasl --eval "(progn (cs430-project:run-all-tests) (quit))"

clean:
	rm project project.fasl
