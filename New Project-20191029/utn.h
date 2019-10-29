#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

//VALIDAR//
int utn_isValidInt(char *string);
int utn_isValidFloat(char *string);
int utn_isValidName(char *string);
int utn_isValidAddress(char *string);

//OBTENER//
int utn_getString(char *pResultado, char *mensaje, char *mensajeError, int min,
		int max, int intentos);
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int min,
		int max, int intentos);
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, int min,
		int max, int intentos);
int utn_getName(char *pResultado, int len, char *mensaje, char *mensajeError,
		int minChars, int maxChars, int intentos);
int utn_getAddress(char *pResultado, int len, char *mensaje, char *mensajeError,
		int minChars, int maxChars, int intentos);

#endif // UTN_H_INCLUDED
