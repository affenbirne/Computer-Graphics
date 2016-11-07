#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// Splits a string in multiple parts which are separated by blanks
void tokenize(const std::string line, std::vector<std::string> &tokens)
{
	std::stringstream iss(line);
	std::string token;
	while( iss >> token)
		tokens.push_back(token);
}

// Loads a matrix from the file filename. The content of this file will be returned via
// the parameter matrix. rowCount and columnCount give the respective number of rows and columns
bool loadMatrix(const char *filename, int **matrix, unsigned int& rowCount, unsigned int& columnCount) 
{
	using namespace std;

	rowCount = 0;
	columnCount = 0;

	ifstream inFile;
	inFile.open(filename, ifstream::in);

	if( !inFile.good())
		return false;

	vector<vector<string>> lines;			// saves the content of the file

	// read data and determine row and column count.
	while( inFile.good()) {

		string line;
		getline(inFile, line);

		if(line == "")
			break;

		vector<string> tokens;
		tokenize(line, tokens);

		columnCount = tokens.size();
		rowCount++;

		lines.push_back(tokens);
	}

	// initialize matrix
	*matrix = new int[ rowCount * columnCount];

	// copy values to the matrix
	for( size_t currentRow=0; currentRow<rowCount; currentRow++) 
	{
		for( size_t currentColumn=0; currentColumn<columnCount; currentColumn++) 
		{
			int value = stoi(lines[currentRow][currentColumn], 0, 10);
			(*matrix)[currentRow * columnCount + currentColumn] = value;
		}
	}

	return true;
}

bool writeMatrix(const char *filename, int *matrix, unsigned int rowCount, unsigned int columnCount)
{
	using namespace std;

	ofstream outFile;
	outFile.open(filename, ofstream::out);

	if( !outFile.good()) {
		return false;
	} else {

		for (size_t i = 0; i < rowCount; ++i) 
		{
			for (size_t j = 0; j < columnCount; ++j) 
			{
				outFile << matrix[i*columnCount + j] << " ";
			}
			outFile << endl;
		}
	}

	return true;
}

//Multiplies the vectors vector1 and vector2 and returns the result.
// There is no check as to the size similarity of vector1 and vector2!
int multiplyVectors(int *vector1, int size1, int offset1,
                    int *vector2, int size2, int offset2)
{
  int result = 0;
  for (int i = 0; i < size1; i++) {
	  result += vector1[i * offset1] * vector2[i * offset2];
  }

  return result;
}


// Multiplies the matrices matrix1 and matrix2 and stores the result in resultMatrix.
// rows and columns for the respective matrices are given.
// If the two matrices can't be multiplied, the function will return false.
bool multiplyMatrices(int *matrix1, int rows1, int columns1, 
                      int *matrix2, int rows2, int columns2,
                      int *resultMatrix)
{
  if (columns1 != rows2)
  {
    return false;
  }
  for (int curRow = 0; curRow < rows1; curRow++) {
	  for (int curCol = 0; curCol < columns2; curCol++) {
		  resultMatrix[curRow * columns2 + curCol] =
			  multiplyVectors(matrix1 + (curRow * columns1), columns1, 1,
				  matrix2 + curCol, rows2, columns2);
	  }
  }
  return true;
}

int main()
{

  int *matrix1;
  int *matrix2;
  unsigned int rows1, rows2, columns1, columns2;

  if (loadMatrix("matrix1.txt", &matrix1, rows1, columns1) &&
      loadMatrix("matrix2.txt", &matrix2, rows2, columns2))
  {
    int *resultMatrix = new int[rows1*columns2];
    multiplyMatrices(matrix1, rows1, columns1, matrix2, rows2, columns2, resultMatrix);
    writeMatrix("matrix3.txt", resultMatrix, rows1, columns2);
    delete[] resultMatrix;
    delete[] matrix1;
    delete[] matrix2;
  }
  else
     printf("Matrixdateien nicht gefunden: ");

  return 0;
}
