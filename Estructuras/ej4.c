#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct header {
    float *secuencia;
    time_t stamp;
    char * frame;
};

struct pose {
    struct {
        double x, y, z;
    } posicion;
    struct {
        double qx, qy, qz, qw;
    } orientacion;
};

struct pose_stamped {
    struct header encabezado;
    struct pose pose1;
} robot_pose;

int main(void) {
  *robot_pose.encabezado.secuencia = 1;
  robot_pose.pose1.posicion.y = 3;
  *robot_pose.encabezado.secuencia = robot_pose.pose1.posicion.y;
  
  return 0;
}
  
