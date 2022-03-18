#pragma once
#include "Application/ApplicationLayer.h"
#include "json.hpp"
#include "../../Gameplay/Scene.h"
#include "../../Gameplay/MeshResource.h"
#include "../../Gameplay/Material.h"
#include "../../Gameplay/GameObject.h"

class SpawnFunctions {

public:
	void SpawnObj(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnStartPlat(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnGem(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr MaterialOn, Gameplay::Material::Sptr MaterialOff, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnCollectable(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnCD(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnWallJump(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnBuilding(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnBuilding2(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnBuilding3(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnSmallWallJump(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnSuperSmallWallJump(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnStairsRight(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnStairsLeft(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnSpeaker(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnSquarePlat(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnFloatingLights(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnBackGroundCar(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnForeGroundCar(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);
	void SpawnBackGroundBuilding(Gameplay::Scene::Sptr scene, Gameplay::MeshResource::Sptr Mesh, Gameplay::Material::Sptr Material, std::string ObjName, glm::vec3 pos,
		glm::vec3 rot, glm::vec3 scale);

};