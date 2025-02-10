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

	// ���� ��ġ�κ��� X�� ���� �Ÿ� ���
	const float DistanceFromStart = FMath::Abs(NewX - StartLocation.X);
	if (DistanceFromStart > MaxRange)
	{
		// �ʰ��� �Ÿ� ����: �ʰ��� ��ŭ ����, �̵� ���� ����
		const float Overshoot = DistanceFromStart - MaxRange;
		NewX -= Overshoot * MoveDirection;
		MoveDirection *= -1;
	}

	// Y, Z ��ǥ�� �״�� �����ϸ� X ��ǥ ������Ʈ
	FVector NewLocation = GetActorLocation();
	NewLocation.X = NewX;
	SetActorLocation(NewLocation);
}

