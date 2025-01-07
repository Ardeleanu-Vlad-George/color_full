TRG := color_shift

OBJ := obj/main.o 

$(TRG) : $(OBJ)
	g++ -o $@ $^ -lsfml-system -lsfml-graphics

$(OBJ) : obj/%.o : src/%.cpp
	g++ -std=c++98 -c -o $@ $^

clean:
	rm $(TRG) $(OBJ)
