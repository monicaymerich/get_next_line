
char	*get_next_line(int fd)
{
	write(fd, &s, 1);
}

void	func_exemple()
{
	static int x = 0; //Sol s'inicialitza una vegada tot i que la cridis més cops
	printf("%d\n", x);
	x = x + 1;
}

//cada cop que es cridi a la funció x valdrà una mes
