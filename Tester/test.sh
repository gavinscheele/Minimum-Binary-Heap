./MinHeap < In1.txt > tmpOut1.txt
PASS = diff tmpOut1.txt Out1.txt
if [ "$PASS" == "" ]; then echo "Test Case 1 Failed.";