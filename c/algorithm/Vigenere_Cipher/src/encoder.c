#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ALPHABET_INIT 32 	// Character space on ASCII
#define ALPHABET_END 127	// Character DEL on ASCII
#define BUFFER_LIMIT 101

/**
 * @brief      Generates a array with the shift to encipher, based on key chars values
 *
 * @param      key         String with the key used to cipher
 * @param      shiftArray  A array to guards the values of shifts.
 */
void generateShiftArray( char * key, int * shiftArray )
{
	int index;
	for( index = 0; index < strlen( key ); index++ )
	{
		shiftArray[ index ] = key[ index ] - ALPHABET_INIT + 1;
	}
}

/**
 * @brief      Cipher a character
 *
 * @param[in]  shift         The shift to plus on original character
 * @param[in]  originalChar  The original character to be ciphered.
 *
 * @return     Returns the ciphered character
 */
char generateChar( int shift, char originalChar  )
{
	if( originalChar < ALPHABET_INIT || originalChar > ALPHABET_END )
	{
		return originalChar;
	}
	int newChar = originalChar + shift;

	if( newChar > ALPHABET_END ) 
	{
		int diff = newChar - ALPHABET_END;
		newChar = ALPHABET_INIT + diff - 1; // -1 because the first alphabet's char is counted twice
	}

	return newChar;
}

/**
 * @brief      Encodes the input text file and saves in other file.
 *
 * @param      inputFile  		The pointer to the input text file
 * @param      key        		The key used to encode the original text
 * @param      outputFileName   The string representing the name of output encoded file
 *
 * @return     0 if the cipher is successfull, 1 in otherwise.
 */
int encode( FILE * inputFile, char * key, char * outputFileName )
{
	int letterIndex = 0;
	printf( "Ciphering the file to %s file\n", outputFileName );

	int * shiftArray = malloc( strlen(key) * sizeof(int) );
	generateShiftArray( key, shiftArray );

	FILE * outputFile = fopen( outputFileName, "w" );

	if( outputFile == NULL )
	{
		printf( "Error to create the ouput file\n>>> Exiting the application without complete " );
		return 1;
	}

	char buffer[BUFFER_LIMIT]; // array to bufferize 100 characters of the original file content. The last one char is '\0'.
	char encryptedBuffer[BUFFER_LIMIT];  // array to bufferize 100 characters of the encrypted file content. The last one char is '\0'.
    while( fgets( buffer, 100, inputFile ) != NULL )
	{
		int i;
		for( i = 0; buffer[ i ] != '\0'; i++, letterIndex++ )
		{
			encryptedBuffer[ i ] = generateChar( shiftArray[  letterIndex % strlen( key ) ], buffer[ i ] );
		}
		encryptedBuffer[ i ] = '\0';
		fprintf( outputFile, "%s", encryptedBuffer ); 
	}
	fclose( outputFile );
	free( shiftArray );

	char buff[ BUFFER_LIMIT ];

	snprintf( buff, sizeof(buff), "mv %s build/", outputFileName ); 
	system( buff );

	return 0;
}


int main( int argc, char ** argv )
{
	if( argc != 4 )
	{	
		printf( "Invalid Arguments!\n" );
		return 1;
	} 
	
	FILE * inputFile = fopen( argv[1], "r" );

	if( inputFile == NULL )
	{
		printf( "Cannot open the input file: %s\n", argv[1] );
		return 1;
	}

	char * key = ( char * ) malloc( sizeof( char ) * ( ALPHABET_END - ALPHABET_INIT ) + 1 );
	strcpy( key, argv[2] );	// copies the key to a string variable
	
	int success = encode( inputFile, key, argv[3] );

	if( success == 0 )
	{
		printf( ">>> Sucessfull encode\n>>> Saving a file named %s on build/ directory\n", argv[3] );
	}

	printf( "\n>>> Exiting...\n" );

	free( key );
	fclose( inputFile );
	return 0;

}
