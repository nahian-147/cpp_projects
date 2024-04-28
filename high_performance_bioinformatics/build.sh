cd genome/build/
cmake -S ../src -B .
echo "Building Libraries"
make
sudo make install

cd ../../src
cmake -S ../src -B .
echo "Building Main"
make
sudo make install
