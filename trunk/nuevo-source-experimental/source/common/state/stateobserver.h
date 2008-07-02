#ifndef __STATEOBSERVER_H__
#define __STATEOBSERVER_H__

#include "attacking.h"
#include "defending.h"
#include "moving.h"
#include "occupying.h"
#include "populating.h"
#include "simplepopulating.h"
#include "waitingmapselection.h"
#include "waitingplayer.h"
#include "waitingfirstplayer.h"

/**
 * Clase observadora de cambios de estado estado.
 */
class StateObserver {
	/**
	 * Metodos protegidos de la clase StateObserver.
	 */
	protected:
		/**
		 * Constructor de la clase StateObserver.
		 */
		StateObserver();
	/**
	 * Mètodos publicos de la clase StateObsever.
	 */
	public:
		/**
		 * Recibio un estado Attacking.
		 */
		virtual void stateChanged(const Attacking& state);
		/**
		 * Recibio un estado Defending.
		 */
		virtual void stateChanged(const Defending& state);
		/**
		 * Recibo un estado Moveing.
		 */
		virtual void stateChanged(const Moving& state);
		/**
		 * Recibo un estado Occupying.
		 */
		virtual void stateChanged(const Occupying& state);
		/**
		 * Recibo un estado Populating.
		 */
		virtual void stateChanged(const Populating& state);
		/**
		 * Recibo un estado SimplePopulating.
		 */
		virtual void stateChanged(const SimplePopulating& state);
		/**
		 * Recibo un estado Waiting.
		 */
		//virtual void stateChanged(const Waiting& state);
		/**
		 * Recibo un estado WaitingMapSelection.
		 */
		virtual void stateChanged(const WaitingMapSelection& state);
		/**
		 * Recibo un estado WaitingPlayer.
		 */
		virtual void stateChanged(const WaitingPlayer& state);
		/**
		 * Recibo un estado WaitingFirstPlayer.
		 */
		virtual void stateChanged(const WaitingFirstPlayer& state);
		/**
		 * Destructor virtual de la clase StateObserver,
		 */
		virtual ~StateObserver();
};
 
#endif /** __STATEOBSERVER_H__ */

