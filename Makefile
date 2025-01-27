TRG := color_shift

OBJ := obj/main.o obj/io.o obj/redgrnblu.o

$(TRG) : $(OBJ)
	g++ -o $@ $^ -lsfml-system -lsfml-graphics

$(OBJ) : obj/%.o : src/%.cpp
	g++ -I inc/ -std=c++98 -c -o $@ $^

clean:
	rm $(TRG) $(OBJ)
