#pragma once
#include "SpawnLoop.h"
#include "Gameplay/Components/BeatTimer.h"
#include <GLFW/glfw3.h>
#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Utils/ImGuiHelper.h"
#include "Application/Layers/SpawnFunctions.h"
#include "Application/Application.h"
#include "Gameplay/MeshResource.h"
#include "Gameplay/Material.h"
#include "Gameplay/GameObject.h"
#include "Utils/ResourceManager/ResourceManager.h"
#include "Utils/FileHelpers.h"



SpawnLoop::SpawnLoop() {

}
void SpawnLoop::Awake() {

	nlohmann::ordered_json data = ResourceManager::GetManifest();

	CreateList(data);
	using namespace Gameplay;
	
	Scene::Sptr scene = Application::Get().CurrentScene();
	
	//Loads The Resource From the Manifest using the human-readable names
	
	//Meshes
	monkeyMesh				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	SmallPlatform			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	WallJump				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	BeatGem					= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	Vinyl					= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	CD						= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	Building				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	KBuilding1Mesh			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	KBuilding2Mesh			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	KBuilding3Mesh			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	OvalBuilding			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	CharacterMesh			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBallMesh			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	StartPlatform			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	Car1Mesh				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	SemiTruckMesh			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	PickupTruckMesh			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	SmallWallJump			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	SuperSmallWallJump		= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	FallingPlat				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	HalfCirclePlat			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	StairsRight				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	StairsLeft				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	Speaker					= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	SquarePlat				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	FloatingLight			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBotMesh1			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBotMesh2			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBotMesh3			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBotMesh4			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBotMesh5			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBotMesh6			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBotMesh7			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBotMesh8			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	DiscoBotMesh9			= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	BotJump1				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	BotJump2				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	BotJump3				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	BotJump4				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	BotJump5				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	BotJump6				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);
	BotJump7				= ResourceManager::Get<MeshResource>(MeshList.find("Monkey.obj")->second);

	//Materials
	StartPlatformMaterial			= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	UIMat							= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	SmallPlatformMaterial			= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	WallJumpMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	BeatGemMaterial					= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	BeatGemOffMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	VinylMaterial					= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	CDMaterial						= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	CharacterMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	DiscoBallMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	LoseScreenMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	Car1Material					= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	SemiTruckMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	PickupTruckMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	BuildingMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	KBuildingMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	KBuilding2Material				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	KBuilding3Material				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	SmallWallJumpMaterial			= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	SuperSmallWallJumpMaterial		= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	PianoMaterial					= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	HalfCirclePlatMaterial			= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	StairsRightMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	StairsLeftMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	SpeakerMaterial					= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	SquarePlatMaterial				= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	FloatingLightMaterial			= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));
	OvalBuildingMaterial			= ResourceManager::Get<Material>((MaterialList.find("SmallPlatform")->second));

}


void SpawnLoop::CreateList(const nlohmann::json& blob) {
	using namespace Gameplay;
	//It's probably more efficient to grab these values Directly form the manifest since
	//they're already loaded there but iterating through JSON's is Icky....

	//Performs some Operation(s) for Every Resource of each type
	ResourceManager::Each<Material>([&](const Material::Sptr& Mat) {

		if (Mat == nullptr) {
			return;
		}
		//Map the GUID created on App start to a human-readable name
		MaterialList.insert(std::pair<std::string, Guid>(Mat->Name, Mat->GetGUID()));

		});

	ResourceManager::Each<MeshResource>([&](const MeshResource::Sptr& Mesh) {
		if (Mesh == nullptr) {
			return;
		}
		//Map the GUID created on App start to a human-readable name
		MeshList.insert(std::pair<std::string, Guid>(Mesh->Filename, Mesh->GetGUID()));

		});



}

void SpawnLoop::SpawnBlock() {
	//This is Disgusting.

	using namespace Gameplay;

	SpawnFunctions Spawner;
	Application& app = Application::Get();
	Scene::Sptr scene = app.CurrentScene();
	float distanceFromBlock = 22;

	switch (_BlockToSpawn) {
	case 0:
		// 1st Block
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "StartPlatform", glm::vec3(-9.820f + distanceFromBlock, 5.610f, -4.450), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-6.070f + distanceFromBlock, 5.610f, -4.150f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-2.840f + distanceFromBlock, 5.610f, -4.150f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(2.760f + distanceFromBlock, 5.610f, -1.770f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnGem(scene, BeatGem, BeatGemMaterial, BeatGemOffMaterial, "BeatGem", glm::vec3(0.120f + distanceFromBlock, 5.610f, -3.160f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnCollectable(scene, Vinyl, VinylMaterial, "Vinyl", glm::vec3(5.640f + distanceFromBlock, 5.610f, 0.080f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "EndPlatform", glm::vec3(6.360f + distanceFromBlock, 5.610f, -4.920f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));

		// CDs for Block 1
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.030f + distanceFromBlock, 5.610f, -3.220f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-2.710f + distanceFromBlock, 5.610f, -3.190f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(0.170f + distanceFromBlock, 5.610f, -2.380f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(2.640f + distanceFromBlock, 5.610f, -0.770f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));

		break;
	case 1:
		//spawn block 2
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "StartPlatform", glm::vec3(-9.820f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnWallJump(scene, WallJump, WallJumpMaterial, "Wall Jump", glm::vec3(-8.590f + distanceFromBlock, 5.610f, 3.210f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.040f, 1.500f));
		Spawner.SpawnFunctions::SpawnWallJump(scene, WallJump, WallJumpMaterial, "Wall Jump", glm::vec3(-6.660f + distanceFromBlock, 5.610f, 2.000f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.040f, 1.500f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-4.400f + distanceFromBlock, 5.610f, 4.000f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(1.940f + distanceFromBlock, 5.610f, -4.150f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnGem(scene, BeatGem, BeatGemMaterial, BeatGemOffMaterial, "BeatGem", glm::vec3(-1.340f + distanceFromBlock, 5.610f, 0.500f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "EndPlatform", glm::vec3(6.360f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));

		// CDs for Block 2
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-7.720f + distanceFromBlock, 5.610f, -0.030f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-7.720f + distanceFromBlock, 5.610f, 2.130f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-7.720f + distanceFromBlock, 5.610f, 4.610f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-4.420f + distanceFromBlock, 5.610f, 4.750f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-1.340f + distanceFromBlock, 5.610f, 0.810f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(1.920f + distanceFromBlock, 5.610f, -3.610f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		break;
	case 2:
		//spawn block 3
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "StartPlatform", glm::vec3(-9.820f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-4.360f + distanceFromBlock, 5.610f, -0.290f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(0.350f + distanceFromBlock, 5.610f, -0.290f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, FallingPlat, PianoMaterial, "Falling Platform", glm::vec3(0.390f + distanceFromBlock, 5.610f, -4.150f), glm::vec3(180.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(3.220f + distanceFromBlock, 5.610f, -4.150f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnGem(scene, BeatGem, BeatGemMaterial, BeatGemOffMaterial, "BeatGem", glm::vec3(-6.870f + distanceFromBlock, 5.610f, -1.970f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnGem(scene, BeatGem, BeatGemMaterial, BeatGemOffMaterial, "BeatGem", glm::vec3(-1.870f + distanceFromBlock, 5.610f, -1.970f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnCollectable(scene, Vinyl, VinylMaterial, "Vinyl", glm::vec3(0.370f + distanceFromBlock, 5.610f, -2.830f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "EndPlatform", glm::vec3(6.360f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));

		// CDs for Block 3
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-4.390f + distanceFromBlock, 5.610f, 0.440f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(0.350f + distanceFromBlock, 5.610f, 0.290f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(3.260f + distanceFromBlock, 5.610f, -3.210f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.690f + distanceFromBlock, 5.610f, -1.180f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		break;
	case 3:
		//spawn block 4
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "StartPlatform", glm::vec3(-9.820f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-6.540f + distanceFromBlock, 5.610f, -4.220f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-3.640f + distanceFromBlock, 5.610f, -4.220f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(2.290f + distanceFromBlock, 5.610f, 4.700f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnSpeaker(scene, Speaker, SpeakerMaterial, "Speaker", glm::vec3(3.400f + distanceFromBlock, 6.410f, -0.090f), glm::vec3(90.0f, 0.0f, -32.000f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnObj(scene, HalfCirclePlat, HalfCirclePlatMaterial, "Half Circle Platform", glm::vec3(-0.720f + distanceFromBlock, 5.610f, -4.220f), glm::vec3(-90.000f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnBuilding(scene, Building, BuildingMaterial, "Building", glm::vec3(4.150f + distanceFromBlock, 5.610f, -7.110f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnWallJump(scene, WallJump, WallJumpMaterial, "Wall Jump", glm::vec3(-1.590f + distanceFromBlock, 5.610f, 2.650f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnWallJump(scene, WallJump, WallJumpMaterial, "Wall Jump", glm::vec3(0.460f + distanceFromBlock, 5.610f, 1.610), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnGem(scene, BeatGem, BeatGemMaterial, BeatGemOffMaterial, "BeatGem", glm::vec3(1.770f + distanceFromBlock, 5.610f, -3.520f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		//Spawner.SpawnFunctions::SpawnCollectable(scene, Vinyl, VinylMaterial, "Vinyl", glm::vec3(2.190f + distanceFromBlock, 5.610f, 5.390f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "EndPlatform", glm::vec3(8.700f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));

		// CDs for Block 4
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.330f + distanceFromBlock, 5.610f, -3.310f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-3.570f + distanceFromBlock, 5.610f, -3.160f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-0.630f + distanceFromBlock, 5.610f, -0.520f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-0.640f + distanceFromBlock, 5.610f, 2.130f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-0.640f + distanceFromBlock, 5.610f, 4.770f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(2.190f + distanceFromBlock, 5.610f, 5.390f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(1.770f + distanceFromBlock, 5.610f, -1.180f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		break;
	case 4:
		//spawn block 5
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "StartPlatform", glm::vec3(-9.820f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-6.540f + distanceFromBlock, 5.610f, -4.220f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-5.000f + distanceFromBlock, 5.610f, -2.830f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-3.550f + distanceFromBlock, 5.610f, -1.410f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-3.330f + distanceFromBlock, 5.610f, 5.950f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(2.280f + distanceFromBlock, 5.610f, 4.180f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(2.280f + distanceFromBlock, 5.610f, -4.010f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnSquarePlat(scene, SquarePlat, SquarePlatMaterial, "Square Platform", glm::vec3(-6.210f + distanceFromBlock, 5.610f, -0.010f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnSmallWallJump(scene, SmallWallJump, SmallWallJumpMaterial, "Small Wall Jump", glm::vec3(-6.730f + distanceFromBlock, 5.610f, 4.460f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnSmallWallJump(scene, SmallWallJump, SmallWallJumpMaterial, "Small Wall Jump", glm::vec3(-5.030f + distanceFromBlock, 5.610f, 4.110f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnSmallWallJump(scene, SmallWallJump, SmallWallJumpMaterial, "Small Wall Jump", glm::vec3(-1.590f + distanceFromBlock, 5.610f, 2.650f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnSmallWallJump(scene, SmallWallJump, SmallWallJumpMaterial, "Small Wall Jump", glm::vec3(0.460f + distanceFromBlock, 5.610f, 1.610f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnGem(scene, BeatGem, BeatGemMaterial, BeatGemOffMaterial, "BeatGem", glm::vec3(-0.580f + distanceFromBlock, 5.610f, -1.970f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnCollectable(scene, Vinyl, VinylMaterial, "Vinyl", glm::vec3(2.190f + distanceFromBlock, 5.610f, 5.390f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "EndPlatform", glm::vec3(6.840f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));

		// CDs for Block 5
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.040f + distanceFromBlock, 5.610f, 2.340f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.040f + distanceFromBlock, 5.610f, 5.170f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-0.630f + distanceFromBlock, 5.610f, 0.460f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-0.640f + distanceFromBlock, 5.610f, 2.710f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(2.170f + distanceFromBlock, 5.610f, -2.880f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		break;
	case 5:

		//block 6
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "StartPlatform", glm::vec3(-9.820f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-6.540f + distanceFromBlock, 5.610f, -4.220f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-5.000f + distanceFromBlock, 5.610f, -2.830f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-3.550f + distanceFromBlock, 5.610f, -1.410f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(4.650f + distanceFromBlock, 5.610f, 2.020f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(7.500f + distanceFromBlock, 5.610f, 0.720f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(4.650f + distanceFromBlock, 5.610f, -1.110f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(7.500f + distanceFromBlock, 5.610f, -2.630f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnSpeaker(scene, Speaker, SpeakerMaterial, "Speaker", glm::vec3(0.840f + distanceFromBlock, 6.410f, 2.360f), glm::vec3(90.0f, 0.0f, -32.000f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnSmallWallJump(scene,SmallWallJump, SmallWallJumpMaterial, "Small Wall Jump", glm::vec3(-2.600f + distanceFromBlock, 5.610f, 5.940f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnSmallWallJump(scene,SmallWallJump, SmallWallJumpMaterial, "Small Wall Jump", glm::vec3(-1.170f + distanceFromBlock, 5.610f, 6.950f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnBuilding(scene,Building, BuildingMaterial, "Building Block6 1", glm::vec3(-1.010f + distanceFromBlock, 5.610f, -4.960f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.310f, 0.310f, 0.310f));
		Spawner.SpawnFunctions::SpawnBuilding(scene,Building, BuildingMaterial, "Building Block6 2", glm::vec3(2.070f + distanceFromBlock, 5.610f, -3.810f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.310f, 0.310f, 0.310f));
		Spawner.SpawnFunctions::SpawnCollectable(scene, Vinyl, VinylMaterial, "Vinyl", glm::vec3(-1.890f + distanceFromBlock, 5.610f, 5.390f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "EndPlatform", glm::vec3(6.840f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));

		// CDs for Block 6
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.510f + distanceFromBlock, 5.610f, -3.190f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-3.500f + distanceFromBlock, 5.610f, -0.740f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-1.190f + distanceFromBlock, 5.610f, 1.590f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(4.650f + distanceFromBlock, 5.610f, 2.630f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(7.420f + distanceFromBlock, 5.610f, 1.290f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(4.650f + distanceFromBlock, 5.610f, -0.480f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(7.420f + distanceFromBlock, 5.610f, -1.980f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		break;
	case 6:
		//block 7
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "StartPlatform", glm::vec3(-9.820f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-4.170f + distanceFromBlock, 5.610f, 2.210f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-0.810f + distanceFromBlock, 5.610f, 2.270f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-0.100f + distanceFromBlock, 5.610f, -1.110f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnSpeaker(scene, Speaker, SpeakerMaterial, "Speaker", glm::vec3(3.400f + distanceFromBlock, 6.410f, 2.560f), glm::vec3(90.0f, 0.0f, -32.000f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnStairsLeft(scene, StairsLeft, StairsLeftMaterial, "Stairs Left", glm::vec3(-1.250f + distanceFromBlock, 5.610f, -0.920f), glm::vec3(90.0f, 0.0f, 90.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnSmallWallJump(scene,SmallWallJump, SmallWallJumpMaterial, "Small Wall Jump", glm::vec3(-8.210f + distanceFromBlock, 5.610f, 2.050f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnSmallWallJump(scene,SmallWallJump, SmallWallJumpMaterial, "Small Wall Jump", glm::vec3(-5.780f + distanceFromBlock, 5.610f, 0.380f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnBuilding(scene, Building, BuildingMaterial, "Building", glm::vec3(4.130f + distanceFromBlock, 5.610f, -3.610f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.310f, 0.310f, 0.310f));
		Spawner.SpawnFunctions::SpawnGem(scene, BeatGem, BeatGemMaterial, BeatGemOffMaterial, "BeatGem", glm::vec3(1.350f + distanceFromBlock, 5.610f, 1.180f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnCollectable(scene, Vinyl, VinylMaterial, "Vinyl", glm::vec3(-0.180f + distanceFromBlock, 5.610f, -0.330f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "EndPlatform", glm::vec3(6.840f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));

		// CDs for Block 7
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.980f + distanceFromBlock, 5.610f, -0.950f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.990f + distanceFromBlock, 5.610f, 2.340f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-4.230f + distanceFromBlock, 5.610f, 2.760f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-0.720f + distanceFromBlock, 5.610f, 2.760f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		break;
	case 7:
		// 8th Block

		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "StartPlatform", glm::vec3(-9.820f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-6.640f + distanceFromBlock, 5.610f, -4.140f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-4.430f + distanceFromBlock, 5.610f, -3.310f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnStairsRight(scene, StairsRight, StairsRightMaterial, "Stairs Right", glm::vec3(-0.320f + distanceFromBlock, 5.610f, -5.570f), glm::vec3(90.0f, 0.0f, 90.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnSpeaker(scene, Speaker, SpeakerMaterial, "Speaker", glm::vec3(3.410f + distanceFromBlock, 6.410f, -0.350f), glm::vec3(90.0f, 0.0f, -32.000f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnBuilding(scene, Building, BuildingMaterial, "Building", glm::vec3(4.570f + distanceFromBlock, 5.610f, -6.630f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.310f, 0.310f, 0.310f));
		Spawner.SpawnFunctions::SpawnBuilding2(scene,Building, BuildingMaterial, "Building", glm::vec3(-4.500f + distanceFromBlock, 5.610f, 7.810f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnBuilding3(scene,Building, BuildingMaterial, "Building", glm::vec3(-1.350f + distanceFromBlock, 5.610f, 5.180f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.290f, 0.290f, 0.290f));
		Spawner.SpawnFunctions::SpawnGem(scene, BeatGem, BeatGemMaterial, BeatGemOffMaterial, "BeatGem", glm::vec3(-2.630f + distanceFromBlock, 5.610f, -4.550f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnSuperSmallWallJump(scene,SuperSmallWallJump, SuperSmallWallJumpMaterial, "Super Small Wall Jump", glm::vec3(2.400f + distanceFromBlock, 5.610f, -3.180f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnSuperSmallWallJump(scene,SuperSmallWallJump, SuperSmallWallJumpMaterial, "Super Small Wall Jump", glm::vec3(0.700f + distanceFromBlock, 5.610f, -1.510f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnSuperSmallWallJump(scene,SuperSmallWallJump, SuperSmallWallJumpMaterial, "Super Small Wall Jump", glm::vec3(2.400f + distanceFromBlock, 5.610f, -0.590f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnSuperSmallWallJump(scene,SuperSmallWallJump, SuperSmallWallJumpMaterial, "Super Small Wall Jump", glm::vec3(0.700f + distanceFromBlock, 5.610f, 0.700f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.210f, 1.500f));
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "EndPlatform", glm::vec3(8.870f + distanceFromBlock, 5.610f, -9.10f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));

		// CDs for Block 8
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.540f + distanceFromBlock, 5.610f, -3.410f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-4.320f + distanceFromBlock, 5.610f, -2.620f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(1.540f + distanceFromBlock, 5.610f, -0.020f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(1.500f + distanceFromBlock, 5.610f, -4.260f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(4.170f + distanceFromBlock, 5.610f, 0.400f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		break;

	default:
		// 1st Block
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "StartPlatform", glm::vec3(-9.820f + distanceFromBlock, 5.610f, -4.450), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene, SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-6.070f + distanceFromBlock, 5.610f, -4.150f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(-2.840f + distanceFromBlock, 5.610f, -4.150f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnObj(scene,SmallPlatform, SmallPlatformMaterial, "Small Platform", glm::vec3(2.760f + distanceFromBlock, 5.610f, -1.770f), glm::vec3(180.0f, 0.0f, 180.0f), glm::vec3(0.350f, 0.350f, 0.350f));
		Spawner.SpawnFunctions::SpawnGem(scene,BeatGem, BeatGemMaterial, BeatGemOffMaterial, "BeatGem", glm::vec3(0.120f + distanceFromBlock, 5.610f, -3.160f), glm::vec3(90.0f, 0.0f, 180.0f), glm::vec3(0.500f, 0.500f, 0.500f));
		Spawner.SpawnFunctions::SpawnCollectable(scene, Vinyl, VinylMaterial, "Vinyl", glm::vec3(5.640f + distanceFromBlock, 5.610f, 0.080f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnStartPlat(scene, StartPlatform, StartPlatformMaterial, "EndPlatform", glm::vec3(6.360f + distanceFromBlock, 5.610f, -4.920f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(0.350f, 0.350f, 0.350f));

		// CDs for Block 1
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-6.030f + distanceFromBlock, 5.610f, -3.220f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(-2.710f + distanceFromBlock, 5.610f, -3.190f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(0.170f + distanceFromBlock, 5.610f, -2.380f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		Spawner.SpawnFunctions::SpawnCD(scene, CD, CDMaterial, "CD", glm::vec3(2.640f + distanceFromBlock, 5.610f, -0.770f), glm::vec3(90.000f, 0.0f, 90.000f), glm::vec3(1.000f, 1.000f, 1.000f));
		break;
	}
}

int SpawnLoop::ToSpawn() {
	_SpawnTimer -= 22;

	if(!_isDirty)
	_BlockToSpawn = rand() % 8;

	return _BlockToSpawn;
}

void SpawnLoop::RenderImGui(){
	//ImGui::Text("Difficulty:   %s", "Easy");
	//ImGui::Separator();
	//ImGui::Text("Currently Spawning:	%s", _BlockToSpawn);
	//ImGui::Text("Time to Next Spawn:	%s", _SpawnTimer);

}
float SpawnLoop::GetSpawnTimer() {
	return _SpawnTimer;
}
SpawnLoop::Sptr SpawnLoop::FromJson(const nlohmann::json& blob) {
	SpawnLoop::Sptr result = std::make_shared<SpawnLoop>();
	result->_Difficulty = blob["Difficulty"];
	return result;
}

nlohmann::json SpawnLoop::ToJson() const {
	return {
		{ "Difficulty", _Difficulty }
	};
}
void SpawnLoop::Update(float dt) {

	_SpawnTimer += dt;
	if (_SpawnTimer >= 22) {
		ToSpawn();
	}

}
