#ifndef DICE_H_
#define DICE_H_


/**
 * Clase que representa un dado del juego.
 */ 

class Dice
{
		
	public:
	
	/**
	 * Constructor de la clase.
	 */
	Dice();
	
	/**
	 * Destructor de la clase.
	 */
	virtual ~Dice();
	
	/**
	 * Metodo virtual cuyo proposito es simular la tirada de dados.
	 * Se debera implementar de acuerdo a la forma en que se quiera generar el valor que obtiene el dado.
	 * Devuelve el numero de dado que se obtuvo, que sera un valor entre 1 y 6, numeros permitidos en el juego.
	 */
	virtual int roll() =0 ;
	
	/**
	 * Metodo virtual cuyo proposito es simular la tirada de dados.
	 * Se debera implementar de acuerdo a la forma en que se quiera generar el valor que obtiene el dado.
	 * Devuelve el numero de dado que se obtuvo, que sera un valor entre 1 y el limite maximo especificado.
	 */
	virtual int roll(int maxLimit) =0 ;
	
	
};

#endif /*DICE_H_*/
