default:
	g++ MatrixService.cpp testMatrixService.cpp -o test.out
	./test.out
	g++ MatrixService.cpp demoMatrixService.cpp -o demo.out
