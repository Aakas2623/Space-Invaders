#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {

        class ZapperController : public EnemyController
        {
        private:
            float vertical_travel_distance = 100.f;
            float zapper_rate_of_fire = 4.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();

        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void initialize() override;
            void fireBullet();
        };
    }
}