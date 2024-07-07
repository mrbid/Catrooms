![Screenshot of the TuxScape2 game](https://raw.githubusercontent.com/mrbid/Catrooms/main/screenshot.png)

*Explore Space, collect all 20 emoji's to reveal 20 cool characters and try flying the other 68 space ships that are randomly dotted around.*

- **Play Online:** https://pushergames.itch.io/catrooms
- **Flathub:** https://flathub.org/apps/com.voxdsp.TheCatrooms
- **Snapcraft:** https://snapcraft.io/catrooms
- **Windows:** https://github.com/mrbid/catrooms/releases

## input
```
ESCAPE to release mouse lock.
Mouse Move to Look Around.
Arrow Keys or WASD to Move Around.
```

## build
```
sudo apt install --assume-yes libglfw3-dev libglfw3
sudo apt install --assume-yes tcc
sudo apt install --assume-yes upx-ucl
sudo apt install --assume-yes mingw-w64
make
./release/TheCatrooms_linux
```
or
```
make deps
make test
```
You don't need [UPX](https://upx.github.io/) but if you don't have the package you can download the binary from [here](https://github.com/upx/upx/releases).

## attribution
* All assets generated using [LUMA GENIE](https://lumalabs.ai/genie) and [TripoAI](https://www.tripo3d.ai).
