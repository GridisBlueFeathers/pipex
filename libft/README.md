# LIBFT
## 42 School library project
42 School project in which some C standart library and other additional functions are written from scratch using limited amount of other functions (Other Clib/external functions, basically only `maloc` is allowed).

## Usage
Add following variables and rules to makefile of your project:
```
LIBFT_DIR = libft
LIBFT = libft/libft.a
```
```
${LIBFT}:
    ${MAKE} -C ${LIBFT_DIR}
```
Add `${LIBFT}` dependency to all rules that will compile files that use **LIBFT**
And add `-I${LIBFT_DIR}/include` to either includes rule or compile flags
