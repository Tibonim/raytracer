int     is_num(char c)
{
  if (c == '.' || ('0' <= c && c <= '9'))
    return (1);
  else
    return (0);
}

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] && (str[i] == '-' || str[i] == '+'))
    i++;
  while (str[i] != '\0')
    {
      if (is_num(str[i]) == 1)
        i = i + 1;
      else
        return (0);
    }
  return (1);
}

