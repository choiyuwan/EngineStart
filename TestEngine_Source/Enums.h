namespace yw
{
	enum class ComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		Animator,
		End

	};
	enum class LayerType
	{
		None,
		Bg,		
		Player,
		Max = 16,
	};

	enum class ResourceType
	{
		Texture,
		Audio,
		Prefab,
		Animation,
		End
	};

}