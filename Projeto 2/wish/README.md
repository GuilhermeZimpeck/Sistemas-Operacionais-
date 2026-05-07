# wish

Neste projeto, foi criado um shell Unix simples utilizando linguagem C. Uma interface basica de linha de 
comando com base no ambiente Unix, oque impede que esse código funcione no windows, portanto ele não 
consegue ser compilado em um ambiente que não tenha como base de codigos do o UNIX. Entretanto, é possivel
utilizalo em uma maquina virtual, ou com o Windows Subsystem for Linux (WSL) que permite rodar um ambiente Linux 
(distribuições como Ubuntu, Debian, Kali) diretamente no Windows 10/11 sem o peso de uma máquina virtual tradicional.

##

### Shell: `wish`

Shell é basicamente um loop interativo: ele imprime repetidamente o prompt `wish>`
, analisa a entrada, executa o comando especificado naquela linha de entrada,
e aguarda o comando terminar. Isto acontece repetidamente até que o usuário digite 
`exit`.

O shell pode ser invocado com nenhum argumento ou um único argumento, qualquer 
outra coisa é um erro. Aqui está a maneira sem argumento:

```
prompt> ./wish
wish> 
```

O modo acima é chamado de modo interativo, e permite que o usuário digite comandos
diretamente no shell. Entretanto, ele também suporta a modo `batch`‚ que ao invés disso 
lê a entrada de um arquivo passado junto a execução do wish. 

Aqui é um exemplo de como você  pode executar o shell com um arquivo chamado `batch.txt`:

```
prompt> ./wish batch.txt
```
OBS: no modo `batch` nenhum prompt é impresso.
##

## Estrutura do código


### `Paths`

Os paths, são literalmente os caminho que o computador deve percorrer, 
é uma lista ordenada de diretórios, que diz ao shell onde procurar arquivos
executáveis (programas ou comandos).

### `Comandos Built-in `

Na maioria dos casos, o shell executara a função fork para criar um processo
filho, e executar um programa definido pelo usuario, entretanto em alguns casos
como o do codigo `cd`, o programa não cria um novo processo, sendo esse um comando
integrado(buit-in)

### `Redirecionamento`

Tambem é possivel redirecionar a saida do programa para um arquivo
ao invés de para a tela. É possivel fazer isso com o `>`, isso é nomeado 
redirecionamento de padrão saída.

exemplo:
```
prompt> ls -la /tmp > output.txt
```
Nesse caso a saida do `ls -la /tmp` não aparecera na tela, mais sim no arquivo `output.txt`

### `Comandos Paralelos`

Esse shell, tambem pode realizar comando paralelos, oque faz com que varios codigos
ocorram um em seguida do outro, para então, ao termino de todos o usuaria poder
escrever um novo comando. 

Para isso é necessario usar como paramentro simbolo `&`.

```
wish> cmd1 & cmd2 args1 args2 & cmd3 args1
```

Nesse exemplo, ao invés de rodar `cmd1` e esperar por ele terminar,
o shell irá rodar `cmd1`, `cmd2`, e `cmd3` (todos com os argumentos passados) em paralelo.

