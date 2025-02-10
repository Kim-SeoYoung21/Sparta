#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComponent);

	MoveSpeed = 100.f;
	MaxRange = 300.f;
	MoveDirection = 1;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float CurrentX = GetActorLocation().X;
	const float DeltaMovement = MoveSpeed * DeltaTime * MoveDirection;
	float NewX = CurrentX + DeltaMovement;

	// 시작 위치로부터 X축 기준 거리 계산
	const float DistanceFromStart = FMath::Abs(NewX - StartLocation.X);
	if (DistanceFromStart > MaxRange)
	{
		// 초과된 거리 보정: 초과분 만큼 빼고, 이동 방향 반전
		const float Overshoot = DistanceFromStart - MaxRange;
		NewX -= Overshoot * MoveDirection;
		MoveDirection *= -1;
	}

	// Y, Z 좌표는 그대로 유지하며 X 좌표 업데이트
	FVector NewLocation = GetActorLocation();
	NewLocation.X = NewX;
	SetActorLocation(NewLocation);
}

