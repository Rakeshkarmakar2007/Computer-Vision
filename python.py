import serial
import cv2
import cvzone
from cvzone.HandTrackingModule import HandDetector

# Initialize serial communication
serialcomm = serial.Serial('COM3', 9600)
serialcomm.timeout = 1

# Initialize webcam
cap = cv2.VideoCapture(0)  # Use 0 if you have only one camera
if not cap.isOpened():
    print("Error: Could not open webcam.")
    exit()

# Initialize hand detector
detector = HandDetector(detectionCon=0.5, maxHands=1)

while True:
    success, img = cap.read()
    if not success:
        print("Error: Could not read frame from webcam.")
        break

    img = cv2.resize(img, (500, 350))
    hands, img = detector.findHands(img)
    
    if hands:
        # Assume only one hand is detected since maxHands=1
        hand = hands[0]
        lmList = hand["lmList"]  # List of 21 Landmark points
        bbox = hand["bbox"]  # Bounding box info x,y,w,h
        centerPoint = hand['center']  # Center of the hand cx,cy
        handType = hand["type"]  # Hand Type Left or Right
        
        fingers = detector.fingersUp(hand)
        fingersCount = sum(fingers)  # Sum the number of raised fingers
        
        serialcomm.write(str(fingersCount).encode() + b'\n')  # Send the count followed by a newline

    cv2.imshow('Image', img)  
    if cv2.waitKey(20) & 0xFF == 27:  # Exit on pressing ESC
        break                

# Release resources
cap.release()
cv2.destroyAllWindows()
serialcomm.close()
