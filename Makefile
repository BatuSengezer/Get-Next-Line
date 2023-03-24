NAME			=	libftprintf.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror 
AR				=	ar -rcs
RM				=	rm -rf

SRCS 			=	get_next_line.c \
					get_next_line_utils.c
					
OBJS			=	$(SRCS:.c=.o)

all:				$(NAME)
					@echo all done

$(NAME):			$(OBJS)
					$(AR) $(NAME) $(OBJS)

$(OBJS): 			$(SRCS)
					$(CC) $(CFLAGS) -c $(SRCS)
			
clean:
					$(RM) $(OBJS)
					@echo clean done

fclean:				clean
					$(RM) $(NAME)
					@echo fclean done

re:					fclean all
					@echo re done

.PHONY:				all clean fclean re libft
