mkdir -p tmp
cd tmp
echo $1
if [ $1 ]; then
	cmake -DCMAKE_BUILD_TYPE=DEBUG ..
else
	cmake -DCMAKE_BUILD_TYPE=RELEASE ..
fi
make
