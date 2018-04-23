# A simple Arduino bluetooth project
I was a bit too lazy to draw the schema for the board, but here is a picture

![image](https://preview.ibb.co/mdh3Yc/IMG_20180424_005138.jpg "Just an image")<br>
Just send a `1` to the bluetooth module, HC-05 in this case, and it works like a charm.
Also, I didn't implement any randomize function, I used the Arduino's default one, if you want to use your own, just replace the ```random``` and ```randomSeed``` functions from the code with your own and you're done.
