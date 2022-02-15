#include <sl/Camera.hpp>
int main() {
    // Initialize and open the camera
    sl::Camera zed;
    zed.open();

    // Create a matrix to store the image
    sl::Mat image;
    int i = 0;

    while(i++ < 1000){
        // Grab a frame and retrieve the left image
        zed.grab();
        zed.retrieveImage(image, sl::VIEW::LEFT);
    }
    return 0;
}