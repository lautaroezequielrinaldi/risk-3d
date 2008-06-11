#ifndef DICE_H_
#define DICE_H_


/**
 * Clase que representa un dado del juego.
 */ 

class Dice
{
	
	private:
	
		//int diceNumber;
		
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
	 * Devuelve el numero de dado que se obtuvo.
	 */
	virtual int roll() =0 ;
	
	/**
	 * Metodo cuyo proposito es obtener el valor del dado que se obtuvo al arrojarlo.
	 * Si se pide el valor antes de hacer roll(), el metodo devuelve -1 representando un dado sin valor.
	 */
	 //int getDiceNumber();
	
};

#endif /*DICE_H_*/
