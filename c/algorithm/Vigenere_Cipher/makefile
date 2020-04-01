#Makefile

#Erick de Oliveira Silva

#Compiler
CXX = gcc

#Flags
COMPILE_FLAG = -std=c11

#Path
SRC_ENCODER_PATH = src/encoder.c
SRC_DECODER_PATH = src/decoder.c

#Executable
BIN_ENCODER_NAME = bin/encoder
BIN_DECODER_NAME = bin/decoder

make:
	if [ ! -d bin/ ]; then mkdir bin/; fi
	if [ ! -d build/ ]; then mkdir build/; fi
	$(CXX) -Wall $(COMPILE_FLAG) $(SRC_ENCODER_PATH) -o $(BIN_ENCODER_NAME)
	$(CXX) -Wall $(COMPILE_FLAG) $(SRC_DECODER_PATH) -o $(BIN_DECODER_NAME)

clean:
	-rm -rf build/
	-rm -rf bin/