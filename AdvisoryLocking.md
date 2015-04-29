es un lockin que no esta forzado por el sistema sino por la buena voluntad de los clientes


```
cd risk-3d/documentation/diagrams
touch risk-3d.jude.$DEVELOPER.lock
svn add risk-3d.jude.$DEVELOPER.lock
svn commit -m "locking risk-3d.jude"

(edicion)

svn rm risk-3d.jude.$DEVELOPER.lock
svn commit -m "cambios ..."
```