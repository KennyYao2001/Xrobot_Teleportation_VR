using UnityEngine;
using TMPro;

public class RecordTextToggle : MonoBehaviour
{
    // Reference to the TextMeshPro component
    public TextMeshPro recordText;

    // State of the recording
    public bool isRecording = false;

    // Store the previous thumbstick state
    private bool wasPressedLastFrame = false;

    private void Update()
    {
        // Get the state of the secondary thumbstick button
        bool isPressed = OVRInput.Get(OVRInput.Button.SecondaryThumbstick);

        // If the thumbstick was just pressed
        if (isPressed && !wasPressedLastFrame)
        {
            ToggleRecording();
        }

        // Update the previous thumbstick state
        wasPressedLastFrame = isPressed;
    }

    private void ToggleRecording()
    {
        isRecording = !isRecording;

        if (isRecording)
        {
            // Set the color to red and show the text
            recordText.color = Color.red;
            recordText.text = "Recording";
        }
        else
        {
            // Hide the text
            recordText.text = "Not Recording";
        }
    }
}
