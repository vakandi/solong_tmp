all: 
	@echo "\033[1;35m\n\n - STARTING COMPILATION -\n\n\033[0m"
	@clang -Wall -Werror -Wextra -g -I includes -I libft -I mlx -c srcs/*.c
	@make -C libft
	@make -C mlx
	@clang -Wall -Werror -Wextra -g -L libft -L mlx *.o -o so_long -lft -lm -lmlx -lXext -lX11
	@if [ -f so_long ]; then echo "\033[1;32m\n\n - COMPILATION SUCCESSFUL -\n\n\033[0m"; echo "\033[1;34m\n\n  Name of the executable: \n\033[0m\033[1;42m        so_long          \033[0m\n\n"; else echo "\033[1;31m\n\n - COMPILATION FAILED -\n\n\033[0m"; fi
	@rm -rf *.o
	
check: all
	@echo "\033[1;35m\n\n - STARTING LEAKS CHECK.. -\n\n\033[0m"
	@valgrind --leak-check=full --tool=memcheck --show-reachable=yes --track-fds=yes --errors-for-leak-kinds=all --show-leak-kinds=all ./so_long
	@echo "\033[1;32m\n\n - CHECKING FINISHED -\n\n\033[0m"

clean:
	@rm -rf *.o
	@make clean -C libft
	@make clean -C mlx
	@rm -rf srcs/*.o

fclean: clean
	@rm -rf so_long
	@make fclean -C libft

re: fclean all
