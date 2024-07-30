test(){
	g++ main.cpp;
	for i in {1..$1}; do cat input$i.txt|./a.out >> output$i.run.txt ; done ;
	for i in {1..$1}; do diff -B output$i.txt output$i.run.txt ;rm output$i.run.txt; done ; 	
}
