#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define SIZE 1000000

typedef struct	s_line
{
  char		*line;
}		t_line;

int	my_len(char *str, int i);
char	*my_realloc(char *str, int l);
int	line_maker(t_line *s, char *buff);
char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
