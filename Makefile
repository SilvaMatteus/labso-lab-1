OUTPUT=xeu
SOURCES=*.cpp xeu_utils/*.cpp

xeu: $(SOURCES)
	g++ $(SOURCES) $(CXXFLAGS) -o $(OUTPUT)

clean:
	
	if [ -f $(OUTPUT) ]; then \
	  rm $(OUTPUT); \
	fi
