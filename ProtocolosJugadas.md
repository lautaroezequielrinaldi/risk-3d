# Protocolos #
Protocolos para las diferentes acciones que puede hacer el jugador


```
<turno>
	<ataque>
		<atacante> idJugador </atacante>
		<defensor>idJugador </defensor>
		<paisAtacante> id  </paisAtacante>
		<paisDfensor> id </paisDfensor>
		<ejercitosAtacantes> cantidad </ejercitosAtacantes>
		<ejercitosDefensores> cantidad </ejercitosDefensores>
	</ataque>
</turno>

```

```
<turno>
	<colocacionEjercito>
		<jugador> id </jugador>
		<paisDestino> id  </paisDestino >
		<infanteria> cantidad </infanteria >
		<caballeria> cantidad </caballeria >
		<artilleria> cantidad </artilleria >
	</colocacionEjercito >
</turno>
```

```
<turno>
	<movimientoTropas>
		<jugador> id </jugador>
		<paisOrigen> id  </paisOrigen >
		<paisDestino> id  </paisDestino >
		<infanteria> cantidad </infanteria >
		<caballeria> cantidad </caballeria >
		<artilleria> cantidad </artilleria >
	</movimientoTropas >
</turno>
```

```
<turno>
	<intercambioEjercitos>
		
                <jugador> id </jugador>
		<paisDestino> id  </ paisDestino >
		<ejercitosAntes>
			<infanteria> cantidad </infanteria >
			<caballeria> cantidad </caballeria >
			<artilleria> cantidad </artilleria >
		</ejercitosAntes>
                <ejercitosDespues>
			<infanteria> cantidad </infanteria >
			<caballeria> cantidad </caballeria >
			<artilleria> cantidad </artilleria >
		</ejercitosDespues >

	</intercambioEjercitos >
</turno>
```

**La idea de**

&lt;ejercitosAntes&gt;

 es detallar la cantidad de denominaciones que tiene y
> va a cambiar
**La idea de**

&lt;ejercitosDespues&gt;

 es detallar la cantidad de denominaciones por las que
> va a cambiar

_Ejemplo:_ si se quiere cambiar 10 ejercitos de infanteria ( valor de c/u = 1 ) por 2 ejercitos de caballeria ( valor de c/u = 5 ), se pasaria:

```
<ejercitosAntes>
               <infanteria> 10 </infanteria >
               <caballeria> </caballeria >
               <artilleria> </artilleria >
</ejercitosAntes>

<ejercitosDespues>
		<infanteria> </infanteria >
		<caballeria> 2 </caballeria >
		<artilleria> </artilleria >
</ejercitosDespues >
```