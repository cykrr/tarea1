#include "csv.h"

/* Lee el archivo csv linea por linea 
 * y crea un struct Song por linea, 
 * guarda respectivamente el nombre,
 * el artista. 
 *
 * Para el género crea 
 * una lista enlazada en el heap de strings (char *).
 *
 * SE ASUME QUE:
 *
 * ningun campo es mayor de 99 chars.
 *
 *
 */
 
 char *saltarComas(char *cadena, int numSaltos){
 	int i=0;
	bool variosGeneros = false;
 	int comasSaltadas = 0;
 	
 	if(numSaltos != 0){
 		while(cadena[i]!='\0'){
 		
 			if(cadena[i] == '\"'){
 				variosGeneros = true;
		 	}
		 
 			if(cadena[i] == ','){
 			
 				if(comasSaltadas == numSaltos){
 				
 					if(variosGeneros){	
 						*(strchr((cadena+i+1), '\"')) = '\0';
					}else{
						*(strchr((cadena+i+1), ',')) = '\0';
					}
 			
		 			return (cadena+i+1);
		 		
				}else{
					numSaltos++;
				}
			}
		 	i++;
	}
	}else{
		*(strchr((cadena+i+1), ',')) = '\0';
		return (cadena);
	}
	 
 }
 
void populateList(CSV *csv){
    ssize_t read; size_t length = 0; char *line = NULL;

    /* leer linea a "read" hasta EOF */
    while((read = getline(&line, &length, csv->fd) != EOF)){
        
        char* nombres;

        nombres = saltarComas(line, 0);

        strcat(buf, nombres);
        strcat(buf, "\n");

    }
}

void CSVimport(CSV *csv, char *name){

    
    csv->fd = fopen(name, "rw");
    if(!csv->fd){
        printf("Error abriendo archivo %s\n", name);
    }


    populateList(csv);
    
}

void CSVexport(CSV *csv, char *name){
    
}

void CSVcreate(CSV *csv){
    csv->fd = NULL;
    csv->list = listCreate();
    csv->name = NULL;
}

