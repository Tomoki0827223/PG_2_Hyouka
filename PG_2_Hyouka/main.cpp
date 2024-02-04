#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
const char kWindowTitle[] = "LC1C_26_ムラタ_トモキ_タイトル";

int Enemy::isAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	int change_Flag = 0;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player;
	Enemy*  enemy  = new Enemy;
	Enemy*  enemy1 = new Enemy;
	
	enemy1->enemypos_.x = 100;
	enemy1->enemypos_.y = 100;

	enum SceneName {
		TITLE,
		SELECT_STAGE,
		LOAD,
		GAME,
		POSE,
		RESULT,
		END
	};

	SceneName screen = TITLE;

	bool isPaused = false;
	int PoseFlag = false;
	//taitol
	int loadingTimer = 0;
	int loadingPos = 0;
	//Pose
	int loadingTimerr = 0;
	int loadingPoss = 0;
	//End
	int EndloadingTimer = 0;
	int EndloadingPoss = 0;

	int taitol = Novice::LoadTexture("./Resources/taitol.png");
	int resporn = Novice::LoadTexture("./Resources/risporn.png");
	int end = Novice::LoadTexture("./Resources/END.png");

	int se = Novice::LoadAudio("./Resources/mp3/SE.mp3");
	int selectFlag = 0;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		switch (screen)
		{
		case TITLE:

			enemy->isAlive = 1;
			player->isbullet_ = 0;
			player->bulletpos_.x = player->outer_.x;
			player->bulletpos_.y = player->outer_.y;

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
			{
				screen = GAME;

				change_Flag = 1;

				//SE
				selectFlag = 1;
				if (selectFlag == 1) {
					Novice::PlayAudio(se, 0, 1);
				}

			}


			loadingTimer += 1;

			if (loadingTimer > 60) {
				loadingPos += 1280;
				loadingTimer = 0;

				if (loadingPos == 1280*2) {
					loadingPos = 0;
				}
			}

			break;
		case SELECT_STAGE:
			break;
		case LOAD:
			break;
		case GAME:

			player->PlayerMove(keys, preKeys);
			player->Bullet1();
			enemy->Hit(player->bulletpos_);
			player->Hit(player->playerpos_, enemy->enemypos_);
			player->Hit(player->playerpos_, enemy1->enemypos_);
			enemy->Move();
			enemy1->Hit(player->bulletpos_);
			enemy1->Move();

			if (enemy->isAlive == 0) {

				screen = END;

			}


			if (keys[DIK_TAB] && preKeys[DIK_TAB] == 0) {

				isPaused = true; // ポーズ状態に移行する
				PoseFlag += 1;



				screen = POSE;
			}

			break;
		case POSE:

			if (keys[DIK_R] && preKeys[DIK_R] == 0) {

					isPaused = false;
					// ゲームに戻る処理
					screen = GAME;
			}


			loadingTimerr += 1;

			if (loadingTimerr > 60) {
				loadingPoss += 1280;
				loadingTimerr = 0;

				if (loadingPoss == 1280 * 2) {
					loadingPoss = 0;
				}
			}

			break;
		case RESULT:
			break;
		case END:

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
			{
				screen = TITLE;

				change_Flag = 1;

				//SE
				selectFlag = 1;
				if (selectFlag == 1) {
					Novice::PlayAudio(se, 0, 1);
				}

			}

			EndloadingTimer += 1;

			if (EndloadingTimer > 60) {
				EndloadingPoss += 1280;
				EndloadingTimer = 0;

				if (EndloadingPoss == 1280 * 2) {
					EndloadingPoss = 0;
				}
			}

			break;
		default:
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		switch (screen)
		{
		case TITLE:

			Novice::DrawSpriteRect(0, 0, loadingPos, 0, 1280, 720, taitol, 1.0f / 2.0f, 1.0f, 0.0f, WHITE);
			Novice::DrawSpriteRect(0, 0, loadingPos, 0, 1280, 720, taitol, 1.0f / 2.0f, 1.0f, 0.0f, WHITE);

			//Novice::DrawSpriteRect(int(load_pos5.x), int(load_pos5.y), loadingPos, 0, 1280, 720, Loading, 0.25f, 1.0f, 0.0f, WHITE);


			break;
		case SELECT_STAGE:
			break;
		case LOAD:
			break;
		case GAME:

			Novice::DrawBox(1, 1, 1280, 720, 0.0f, 0x006400FF, kFillModeSolid);

			player->PlayerDraw();
			enemy->Draw();
			enemy1->Draw();

			Novice::DrawBox(10, 10, 250, 50, 0.0f, BLACK, kFillModeSolid);
			Novice::ScreenPrintf(30, 20, "DIK_TAB = POSE_Menu");

			Novice::ScreenPrintf(30, 40, "dis = %f", enemy1->distance);


			break;
		case POSE:

			Novice::DrawBox(1, 1, 1280, 720, 0.0f, 0x006400FF, kFillModeSolid);

			Novice::DrawSpriteRect(0, 0, loadingPoss, 0, 1280, 720, resporn, 1.0f / 2.0f, 1.0f, 0.0f, WHITE);
			Novice::DrawSpriteRect(0, 0, loadingPoss, 0, 1280, 720, resporn, 1.0f / 2.0f, 1.0f, 0.0f, WHITE);

			break;
		case RESULT:
			break;
		case END:

			Novice::DrawSpriteRect(0, 0, EndloadingPoss, 0, 1280, 720, end, 1.0f / 2.0f, 1.0f, 0.0f, WHITE);
			Novice::DrawSpriteRect(0, 0, EndloadingPoss, 0, 1280, 720, end, 1.0f / 2.0f, 1.0f, 0.0f, WHITE);

			break;
		default:
			break;
		}



		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	delete enemy;
	delete enemy1;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
