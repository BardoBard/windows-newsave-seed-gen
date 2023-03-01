#pragma once
#include <functional>

#include "Newsave.h"
#include "UserInput.h"

namespace CppCLRWinFormsProject
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    inline auto find_seeds_lambda = [&](const Newsave& newsave, const uint_fast32_t start_seed,
                                        const uint_fast32_t end_seed)
    {
        newsave.find_seeds(start_seed, end_seed);
    };

    /// <summary>
    /// Summary for NewsaveWindow
    /// </summary>
    public ref class NewsaveWindow : public System::Windows::Forms::Form
    {
    public:
        NewsaveWindow(void)
        {
            InitializeComponent();
            this->MaximizeBox = false;
        }

        void add_data_to_dropdowns(Generic::Dictionary<int, String^>^ items)
        {
            for each (Control^ control in tableLayoutPanel1->Controls)
            {
                if (control->GetType() == ComboBox::typeid)
                {
                    auto box = static_cast<ComboBox^>(control);

                    if (box == mine1 || box == shoguul || box == shoguul_item1) continue;

                    auto bs = gcnew BindingSource();
                    bs->DataSource = items;

                    box->ValueMember = "Key";
                    box->DisplayMember = "Value";

                    box->DataSource = bs;
                }
            }
        }

        void init_dropdowns()
        {
            Generic::Dictionary<int, String^>^ items = gcnew Generic::Dictionary<int, String^>();
            items->Add(-1, "Anything");
            items->Add(0, "Bottled Lightning");
            items->Add(1, "Butcher's Cleaver");
            items->Add(2, "Bombushka");
            items->Add(3, "Golden Popcorn");
            items->Add(4, "Guidance");
            items->Add(5, "Phantasmal Axe");
            items->Add(6, "Floating Skull");
            items->Add(7, "Salamander Tail");
            items->Add(8, "Fork");

            auto bs = gcnew BindingSource();
            bs->DataSource = items;

            mine1->ValueMember = "Key";
            mine1->DisplayMember = "Value";

            mine1->DataSource = bs;

            items = gcnew Generic::Dictionary<int, String^>();

            items->Add(NOTHING, "Nothing");
            items->Add(2, "mine2");
            items->Add(3, "mine3");
            items->Add(4, "mine4");
            items->Add(6, "dungeon1");
            items->Add(7, "dungeon2");
            items->Add(8, "dungeon3");
            items->Add(9, "dungeon4");
            items->Add(11, "halls1");
            items->Add(12, "halls2");
            items->Add(13, "halls3");
            items->Add(14, "halls4");
            items->Add(16, "caverns1");
            items->Add(17, "caverns2");
            items->Add(18, "caverns3");
            items->Add(19, "caverns4");
            items->Add(21, "core1");
            items->Add(22, "core2");
            items->Add(23, "core3");
            items->Add(24, "core4");

            bs = gcnew BindingSource();
            bs->DataSource = items;

            shoguul->ValueMember = "Key";
            shoguul->DisplayMember = "Value";

            shoguul->DataSource = bs;

            items = gcnew Generic::Dictionary<int, String^>();

            items->Add(0, "Lockpick");
            items->Add(1, "Chakram");
            items->Add(2, "Karmic Scale");
            items->Add(3, "Rabbit Gloves");
            items->Add(4, "Doom Blade");
            items->Add(5, "Mjolnir");
            items->Add(6, "Pocket of Holding");
            items->Add(7, "Miniaturizer");
            items->Add(8, "Nullstone");
            items->Add(9, "Mushroom");
            items->Add(10, "Glass Cannon");
            items->Add(11, "Branding Bomb");
            items->Add(12, "Suneater");
            items->Add(13, "Transmutagen Blast");
            items->Add(14, "Tsar Bomba");
            items->Add(15, "Shield of Quills");
            items->Add(16, "Soul Guard");
            items->Add(17, "Box of Holding");
            items->Add(18, "Stoneforge Broth");

            bs = gcnew BindingSource();
            bs->DataSource = items;

            shoguul_item1->ValueMember = "Key";
            shoguul_item1->DisplayMember = "Value";

            shoguul_item1->DataSource = bs;


            items = gcnew Generic::Dictionary<int, String^>();

            items->Add(NOTHING, "Nothing");
            items->Add(0, "Bombushka");
            items->Add(1, "Seer's Blood");
            items->Add(2, "Rook's Bomb");
            items->Add(3, "Lightning Bomb");
            items->Add(4, "Galoshes");
            items->Add(5, "Bottled Lightning");
            items->Add(6, "Salamander Tail");
            items->Add(7, "Guidance");
            items->Add(8, "Ursine Ring");
            items->Add(9, "Demon Ring");
            items->Add(10, "Intensifier");
            items->Add(11, "Cracked Orb");
            items->Add(12, "Conductor");
            items->Add(13, "Grimhilde's Mirror");
            items->Add(14, "Meal Ticket");
            items->Add(15, "Dillon's Claw");
            items->Add(16, "Bramble Vest");
            items->Add(17, "Leftovers");
            items->Add(18, "Spare Ordnance");
            items->Add(19, "Simple Chest");
            items->Add(20, "Unstable Concoction");
            items->Add(21, "Totem of Life");
            items->Add(22, "Golden Popcorn");
            items->Add(23, "Miner's Flask");
            items->Add(24, "Sewing Kit");
            items->Add(25, "Floating Skull");
            items->Add(26, "Float Boots");
            items->Add(27, "Key Blade");
            items->Add(28, "War Paint");
            items->Add(29, "Sonic Boom");
            items->Add(30, "Gold Frenzy");
            items->Add(31, "Butcher's Cleaver");
            items->Add(32, "Iron Branch");
            items->Add(33, "Knight's Pendant");
            items->Add(34, "Queen's Crown");
            items->Add(35, "Aegis");
            items->Add(36, "Adventurer's Whip");
            items->Add(37, "Axe Thrower's Pendant");
            items->Add(38, "Cosmic Egg");
            items->Add(39, "Battle Standard");
            items->Add(40, "Battle Axe");
            items->Add(41, "Tent");
            items->Add(42, "Masa");
            items->Add(43, "Lunchbox");
            items->Add(44, "Phantasmal Axe");
            items->Add(45, "Gecko Blast");
            items->Add(46, "Soul Cannon");
            items->Add(47, "Greaves");
            items->Add(48, "Pauldron");
            items->Add(49, "Obsidian Knife");
            items->Add(50, "Fork");
            items->Add(51, "Ursa Major");
            items->Add(52, "Canis Major");
            items->Add(53, "Sagitta");
            items->Add(54, "Circinus");
            items->Add(55, "Orion's Sword");
            items->Add(56, "Shrapnel");
            items->Add(57, "Tortoise Shield");
            items->Add(58, "Golden Axe");

            add_data_to_dropdowns(items);
        }


    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~NewsaveWindow()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::ComboBox^ mine1;
    protected:
    protected:
    protected:
    private:
        System::Windows::Forms::Button^ find_seeds_btn;
    private:
        System::Windows::Forms::ComboBox^ mine2;
    private:
        System::Windows::Forms::ComboBox^ mine3;
    private:
        System::Windows::Forms::NumericUpDown^ amount_of_seeds_to_find;

    private:
    private:
        System::Windows::Forms::ComboBox^ mine4;
    private:
        System::Windows::Forms::Label^ label1;
    private:
        System::Windows::Forms::Label^ label2;
    private:
        System::Windows::Forms::Label^ label3;
    private:
        System::Windows::Forms::Label^ label4;
    private:
        System::Windows::Forms::ComboBox^ dungeon1;
    private:
        System::Windows::Forms::Label^ label5;
    private:
        System::Windows::Forms::ComboBox^ Dungeon2;
    private:
        System::Windows::Forms::Label^ label6;
    private:
        System::Windows::Forms::ComboBox^ Dungeon3;
    private:
        System::Windows::Forms::Label^ label7;
    private:
        System::Windows::Forms::ComboBox^ Dungeon4;
    private:
        System::Windows::Forms::Label^ label8;
    private:
    private:
    private:
    private:
    private:
    private:
    private:
    private:
    private:
        System::Windows::Forms::ComboBox^ caverns1;
    private:
        System::Windows::Forms::ComboBox^ caverns2;
    private:
        System::Windows::Forms::ComboBox^ caverns3;
    private:
        System::Windows::Forms::ComboBox^ caverns4;
    private:
        System::Windows::Forms::Label^ label13;
    private:
        System::Windows::Forms::Label^ label14;
    private:
        System::Windows::Forms::Label^ label15;
    private:
        System::Windows::Forms::Label^ label16;
    private:
        System::Windows::Forms::ComboBox^ core1;
    private:
        System::Windows::Forms::ComboBox^ core2;
    private:
        System::Windows::Forms::Label^ label17;
    private:
        System::Windows::Forms::Label^ label18;
    private:
        System::Windows::Forms::ComboBox^ core3;
    private:
        System::Windows::Forms::ComboBox^ core4;
    private:
        System::Windows::Forms::Label^ label19;
    private:
        System::Windows::Forms::Label^ label20;
    private:
        System::Windows::Forms::Label^ label21;
    private:
    private:
    private:
    private:
    private:
    private:
        System::Windows::Forms::Label^ label23;
    private:
        System::Windows::Forms::ComboBox^ shoguul;
    private:
        System::Windows::Forms::ComboBox^ shoguul_item1;
    private:
    private:
        System::Windows::Forms::Label^ label24;
    private:
    private:
    private:
        System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
    private:
        System::Windows::Forms::RichTextBox^ outputbox;
    private:
        System::Windows::Forms::Label^ label9;
    private:
        System::Windows::Forms::ComboBox^ halls1;
    private:
        System::Windows::Forms::Label^ label10;
    private:
        System::Windows::Forms::ComboBox^ halls2;
    private:
        System::Windows::Forms::Label^ label11;
    private:
        System::Windows::Forms::ComboBox^ halls3;
    private:
        System::Windows::Forms::Label^ label12;
    private:
        System::Windows::Forms::ComboBox^ halls4;
    private:
        System::Windows::Forms::Label^ label22;
    private:
        System::Windows::Forms::NumericUpDown^ amount_of_seeds_to_loop;
    private:
        System::Windows::Forms::CheckBox^ RandomizeCheckBox;
    private:
        System::Windows::Forms::Button^ button1;
    private:
        System::Windows::Forms::RadioButton^ NewsaveButton;
    private:
        System::Windows::Forms::RadioButton^ radioButton2;
    private:
        System::Windows::Forms::OpenFileDialog^ FileExplorer;


    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->mine1 = (gcnew System::Windows::Forms::ComboBox());
            this->find_seeds_btn = (gcnew System::Windows::Forms::Button());
            this->mine2 = (gcnew System::Windows::Forms::ComboBox());
            this->mine3 = (gcnew System::Windows::Forms::ComboBox());
            this->amount_of_seeds_to_find = (gcnew System::Windows::Forms::NumericUpDown());
            this->mine4 = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->dungeon1 = (gcnew System::Windows::Forms::ComboBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->Dungeon2 = (gcnew System::Windows::Forms::ComboBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->Dungeon3 = (gcnew System::Windows::Forms::ComboBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->Dungeon4 = (gcnew System::Windows::Forms::ComboBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->caverns1 = (gcnew System::Windows::Forms::ComboBox());
            this->caverns2 = (gcnew System::Windows::Forms::ComboBox());
            this->caverns3 = (gcnew System::Windows::Forms::ComboBox());
            this->caverns4 = (gcnew System::Windows::Forms::ComboBox());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->core1 = (gcnew System::Windows::Forms::ComboBox());
            this->core2 = (gcnew System::Windows::Forms::ComboBox());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->core3 = (gcnew System::Windows::Forms::ComboBox());
            this->core4 = (gcnew System::Windows::Forms::ComboBox());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->shoguul = (gcnew System::Windows::Forms::ComboBox());
            this->shoguul_item1 = (gcnew System::Windows::Forms::ComboBox());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->halls1 = (gcnew System::Windows::Forms::ComboBox());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->halls2 = (gcnew System::Windows::Forms::ComboBox());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->halls3 = (gcnew System::Windows::Forms::ComboBox());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->halls4 = (gcnew System::Windows::Forms::ComboBox());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->amount_of_seeds_to_loop = (gcnew System::Windows::Forms::NumericUpDown());
            this->RandomizeCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->outputbox = (gcnew System::Windows::Forms::RichTextBox());
            this->NewsaveButton = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
            this->FileExplorer = (gcnew System::Windows::Forms::OpenFileDialog());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_of_seeds_to_find))->BeginInit();
            this->tableLayoutPanel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_of_seeds_to_loop))->BeginInit();
            this->SuspendLayout();
            // 
            // mine1
            // 
            this->mine1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->mine1->FormattingEnabled = true;
            this->mine1->Location = System::Drawing::Point(3, 28);
            this->mine1->Name = L"mine1";
            this->mine1->Size = System::Drawing::Size(90, 24);
            this->mine1->TabIndex = 1;
            this->mine1->Text = L"Goldmine1";
            // 
            // find_seeds_btn
            // 
            this->find_seeds_btn->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->find_seeds_btn->Dock = System::Windows::Forms::DockStyle::Fill;
            this->find_seeds_btn->Location = System::Drawing::Point(195, 255);
            this->find_seeds_btn->Name = L"find_seeds_btn";
            this->tableLayoutPanel1->SetRowSpan(this->find_seeds_btn, 2);
            this->find_seeds_btn->Size = System::Drawing::Size(90, 74);
            this->find_seeds_btn->TabIndex = 1;
            this->find_seeds_btn->Text = L"Find Seeds";
            this->find_seeds_btn->UseVisualStyleBackColor = true;
            this->find_seeds_btn->Click += gcnew System::EventHandler(this, &NewsaveWindow::find_seeds_btn_Click);
            // 
            // mine2
            // 
            this->mine2->AllowDrop = true;
            this->mine2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->mine2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine2->FormattingEnabled = true;
            this->mine2->Location = System::Drawing::Point(99, 28);
            this->mine2->Name = L"mine2";
            this->mine2->Size = System::Drawing::Size(90, 24);
            this->mine2->TabIndex = 2;
            // 
            // mine3
            // 
            this->mine3->AllowDrop = true;
            this->mine3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->mine3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine3->FormattingEnabled = true;
            this->mine3->Location = System::Drawing::Point(195, 28);
            this->mine3->Name = L"mine3";
            this->mine3->Size = System::Drawing::Size(90, 24);
            this->mine3->TabIndex = 3;
            // 
            // amount_of_seeds_to_find
            // 
            this->amount_of_seeds_to_find->Dock = System::Windows::Forms::DockStyle::Fill;
            this->amount_of_seeds_to_find->Increment = System::Decimal(gcnew cli::array<System::Int32>(4){5, 0, 0, 0});
            this->amount_of_seeds_to_find->Location = System::Drawing::Point(99, 255);
            this->amount_of_seeds_to_find->Maximum = System::Decimal(gcnew cli::array<System::Int32>(4){
                1000000, 0, 0, 0
            });
            this->amount_of_seeds_to_find->Minimum = System::Decimal(gcnew cli::array<System::Int32>(4){1, 0, 0, 0});
            this->amount_of_seeds_to_find->Name = L"amount_of_seeds_to_find";
            this->amount_of_seeds_to_find->Size = System::Drawing::Size(90, 22);
            this->amount_of_seeds_to_find->TabIndex = 4;
            this->amount_of_seeds_to_find->Value = System::Decimal(gcnew cli::array<System::Int32>(4){10, 0, 0, 0});
            // 
            // mine4
            // 
            this->mine4->AllowDrop = true;
            this->mine4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->mine4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->mine4->FormattingEnabled = true;
            this->mine4->Location = System::Drawing::Point(291, 28);
            this->mine4->Name = L"mine4";
            this->mine4->Size = System::Drawing::Size(90, 24);
            this->mine4->TabIndex = 4;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label1->Location = System::Drawing::Point(3, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(90, 25);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Goldmine 1";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label2->Location = System::Drawing::Point(99, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(90, 25);
            this->label2->TabIndex = 6;
            this->label2->Text = L"Goldmine 2";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label3->Location = System::Drawing::Point(195, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(90, 25);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Goldmine 3";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label4->Location = System::Drawing::Point(291, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(90, 25);
            this->label4->TabIndex = 8;
            this->label4->Text = L"Goldmine 4";
            // 
            // dungeon1
            // 
            this->dungeon1->AllowDrop = true;
            this->dungeon1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dungeon1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->dungeon1->FormattingEnabled = true;
            this->dungeon1->Location = System::Drawing::Point(3, 78);
            this->dungeon1->Name = L"dungeon1";
            this->dungeon1->Size = System::Drawing::Size(90, 24);
            this->dungeon1->TabIndex = 6;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label5->Location = System::Drawing::Point(3, 55);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(90, 20);
            this->label5->TabIndex = 10;
            this->label5->Text = L"Dungeon 1";
            // 
            // Dungeon2
            // 
            this->Dungeon2->AllowDrop = true;
            this->Dungeon2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Dungeon2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Dungeon2->FormattingEnabled = true;
            this->Dungeon2->Location = System::Drawing::Point(99, 78);
            this->Dungeon2->Name = L"Dungeon2";
            this->Dungeon2->Size = System::Drawing::Size(90, 24);
            this->Dungeon2->TabIndex = 7;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label6->Location = System::Drawing::Point(99, 55);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(90, 20);
            this->label6->TabIndex = 12;
            this->label6->Text = L"Dungeon 2";
            // 
            // Dungeon3
            // 
            this->Dungeon3->AllowDrop = true;
            this->Dungeon3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Dungeon3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Dungeon3->FormattingEnabled = true;
            this->Dungeon3->Location = System::Drawing::Point(195, 78);
            this->Dungeon3->Name = L"Dungeon3";
            this->Dungeon3->Size = System::Drawing::Size(90, 24);
            this->Dungeon3->TabIndex = 8;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label7->Location = System::Drawing::Point(195, 55);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(90, 20);
            this->label7->TabIndex = 13;
            this->label7->Text = L"Dungeon 3";
            // 
            // Dungeon4
            // 
            this->Dungeon4->AllowDrop = true;
            this->Dungeon4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->Dungeon4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->Dungeon4->FormattingEnabled = true;
            this->Dungeon4->Location = System::Drawing::Point(291, 78);
            this->Dungeon4->Name = L"Dungeon4";
            this->Dungeon4->Size = System::Drawing::Size(90, 24);
            this->Dungeon4->TabIndex = 9;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label8->Location = System::Drawing::Point(291, 55);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(90, 20);
            this->label8->TabIndex = 14;
            this->label8->Text = L"Dungeon 4";
            // 
            // caverns1
            // 
            this->caverns1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->caverns1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns1->FormattingEnabled = true;
            this->caverns1->Location = System::Drawing::Point(3, 178);
            this->caverns1->Name = L"caverns1";
            this->caverns1->Size = System::Drawing::Size(90, 24);
            this->caverns1->TabIndex = 16;
            // 
            // caverns2
            // 
            this->caverns2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->caverns2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns2->FormattingEnabled = true;
            this->caverns2->Location = System::Drawing::Point(99, 178);
            this->caverns2->Name = L"caverns2";
            this->caverns2->Size = System::Drawing::Size(90, 24);
            this->caverns2->TabIndex = 17;
            // 
            // caverns3
            // 
            this->caverns3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->caverns3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns3->FormattingEnabled = true;
            this->caverns3->Location = System::Drawing::Point(195, 178);
            this->caverns3->Name = L"caverns3";
            this->caverns3->Size = System::Drawing::Size(90, 24);
            this->caverns3->TabIndex = 18;
            // 
            // caverns4
            // 
            this->caverns4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->caverns4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->caverns4->FormattingEnabled = true;
            this->caverns4->Location = System::Drawing::Point(291, 178);
            this->caverns4->Name = L"caverns4";
            this->caverns4->Size = System::Drawing::Size(90, 24);
            this->caverns4->TabIndex = 19;
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label13->Location = System::Drawing::Point(3, 155);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(90, 20);
            this->label13->TabIndex = 26;
            this->label13->Text = L"Caverns 1";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label14->Location = System::Drawing::Point(99, 155);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(90, 20);
            this->label14->TabIndex = 27;
            this->label14->Text = L"Caverns 2";
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label15->Location = System::Drawing::Point(195, 155);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(90, 20);
            this->label15->TabIndex = 28;
            this->label15->Text = L"Caverns 3";
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label16->Location = System::Drawing::Point(291, 155);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(90, 20);
            this->label16->TabIndex = 29;
            this->label16->Text = L"Caverns 4";
            // 
            // core1
            // 
            this->core1->AllowDrop = true;
            this->core1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->core1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core1->FormattingEnabled = true;
            this->core1->Location = System::Drawing::Point(3, 228);
            this->core1->Name = L"core1";
            this->core1->Size = System::Drawing::Size(90, 24);
            this->core1->TabIndex = 21;
            // 
            // core2
            // 
            this->core2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->core2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core2->FormattingEnabled = true;
            this->core2->Location = System::Drawing::Point(99, 228);
            this->core2->Name = L"core2";
            this->core2->Size = System::Drawing::Size(90, 24);
            this->core2->TabIndex = 22;
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label17->Location = System::Drawing::Point(3, 205);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(90, 20);
            this->label17->TabIndex = 30;
            this->label17->Text = L"Core 1";
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label18->Location = System::Drawing::Point(99, 205);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(90, 20);
            this->label18->TabIndex = 31;
            this->label18->Text = L"Core 2";
            // 
            // core3
            // 
            this->core3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->core3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core3->FormattingEnabled = true;
            this->core3->Location = System::Drawing::Point(195, 228);
            this->core3->Name = L"core3";
            this->core3->Size = System::Drawing::Size(90, 24);
            this->core3->TabIndex = 23;
            // 
            // core4
            // 
            this->core4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->core4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->core4->FormattingEnabled = true;
            this->core4->Location = System::Drawing::Point(291, 228);
            this->core4->Name = L"core4";
            this->core4->Size = System::Drawing::Size(90, 24);
            this->core4->TabIndex = 24;
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label19->Location = System::Drawing::Point(195, 205);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(90, 20);
            this->label19->TabIndex = 32;
            this->label19->Text = L"Core 3";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label20->Location = System::Drawing::Point(291, 205);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(90, 20);
            this->label20->TabIndex = 33;
            this->label20->Text = L"Core 4";
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label21->Location = System::Drawing::Point(3, 252);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(90, 40);
            this->label21->TabIndex = 34;
            this->label21->Text = L"Amount of seeds you\'d like to find";
            // 
            // label23
            // 
            this->label23->AutoSize = true;
            this->label23->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F,
                                                               System::Drawing::FontStyle::Regular,
                                                               System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->label23->Location = System::Drawing::Point(387, 0);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(92, 25);
            this->label23->TabIndex = 38;
            this->label23->Text = L"Shoguul";
            // 
            // shoguul
            // 
            this->shoguul->AllowDrop = true;
            this->shoguul->Dock = System::Windows::Forms::DockStyle::Fill;
            this->shoguul->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->shoguul->FormattingEnabled = true;
            this->shoguul->Location = System::Drawing::Point(387, 28);
            this->shoguul->Name = L"shoguul";
            this->shoguul->Size = System::Drawing::Size(92, 24);
            this->shoguul->TabIndex = 39;
            // 
            // shoguul_item1
            // 
            this->shoguul_item1->AllowDrop = true;
            this->shoguul_item1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->shoguul_item1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->shoguul_item1->FormattingEnabled = true;
            this->shoguul_item1->Location = System::Drawing::Point(387, 78);
            this->shoguul_item1->Name = L"shoguul_item1";
            this->shoguul_item1->Size = System::Drawing::Size(92, 24);
            this->shoguul_item1->TabIndex = 40;
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F,
                                                               System::Drawing::FontStyle::Regular,
                                                               System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->label24->Location = System::Drawing::Point(387, 55);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(92, 20);
            this->label24->TabIndex = 42;
            this->label24->Text = L"Item:";
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->AutoScroll = true;
            this->tableLayoutPanel1->ColumnCount = 5;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                20)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                20)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                20)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                20)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                20)));
            this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->mine1, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->find_seeds_btn, 2, 11);
            this->tableLayoutPanel1->Controls->Add(this->shoguul_item1, 4, 3);
            this->tableLayoutPanel1->Controls->Add(this->label24, 4, 2);
            this->tableLayoutPanel1->Controls->Add(this->label2, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->mine2, 1, 1);
            this->tableLayoutPanel1->Controls->Add(this->shoguul, 4, 1);
            this->tableLayoutPanel1->Controls->Add(this->label3, 2, 0);
            this->tableLayoutPanel1->Controls->Add(this->label23, 4, 0);
            this->tableLayoutPanel1->Controls->Add(this->mine3, 2, 1);
            this->tableLayoutPanel1->Controls->Add(this->label4, 3, 0);
            this->tableLayoutPanel1->Controls->Add(this->mine4, 3, 1);
            this->tableLayoutPanel1->Controls->Add(this->label5, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->core4, 3, 9);
            this->tableLayoutPanel1->Controls->Add(this->label20, 3, 8);
            this->tableLayoutPanel1->Controls->Add(this->dungeon1, 0, 3);
            this->tableLayoutPanel1->Controls->Add(this->label19, 2, 8);
            this->tableLayoutPanel1->Controls->Add(this->core3, 2, 9);
            this->tableLayoutPanel1->Controls->Add(this->label6, 1, 2);
            this->tableLayoutPanel1->Controls->Add(this->Dungeon2, 1, 3);
            this->tableLayoutPanel1->Controls->Add(this->label7, 2, 2);
            this->tableLayoutPanel1->Controls->Add(this->core2, 1, 9);
            this->tableLayoutPanel1->Controls->Add(this->label18, 1, 8);
            this->tableLayoutPanel1->Controls->Add(this->Dungeon3, 2, 3);
            this->tableLayoutPanel1->Controls->Add(this->label17, 0, 8);
            this->tableLayoutPanel1->Controls->Add(this->core1, 0, 9);
            this->tableLayoutPanel1->Controls->Add(this->label8, 3, 2);
            this->tableLayoutPanel1->Controls->Add(this->Dungeon4, 3, 3);
            this->tableLayoutPanel1->Controls->Add(this->caverns4, 3, 7);
            this->tableLayoutPanel1->Controls->Add(this->label16, 3, 6);
            this->tableLayoutPanel1->Controls->Add(this->label9, 0, 4);
            this->tableLayoutPanel1->Controls->Add(this->label15, 2, 6);
            this->tableLayoutPanel1->Controls->Add(this->caverns3, 2, 7);
            this->tableLayoutPanel1->Controls->Add(this->halls1, 0, 5);
            this->tableLayoutPanel1->Controls->Add(this->label14, 1, 6);
            this->tableLayoutPanel1->Controls->Add(this->label10, 1, 4);
            this->tableLayoutPanel1->Controls->Add(this->caverns2, 1, 7);
            this->tableLayoutPanel1->Controls->Add(this->label13, 0, 6);
            this->tableLayoutPanel1->Controls->Add(this->halls2, 1, 5);
            this->tableLayoutPanel1->Controls->Add(this->label11, 2, 4);
            this->tableLayoutPanel1->Controls->Add(this->caverns1, 0, 7);
            this->tableLayoutPanel1->Controls->Add(this->halls3, 2, 5);
            this->tableLayoutPanel1->Controls->Add(this->label12, 3, 4);
            this->tableLayoutPanel1->Controls->Add(this->halls4, 3, 5);
            this->tableLayoutPanel1->Controls->Add(this->label22, 0, 12);
            this->tableLayoutPanel1->Controls->Add(this->amount_of_seeds_to_loop, 1, 12);
            this->tableLayoutPanel1->Controls->Add(this->amount_of_seeds_to_find, 1, 11);
            this->tableLayoutPanel1->Controls->Add(this->label21, 0, 11);
            this->tableLayoutPanel1->Controls->Add(this->RandomizeCheckBox, 3, 12);
            this->tableLayoutPanel1->Controls->Add(this->button1, 4, 12);
            this->tableLayoutPanel1->Controls->Add(this->outputbox, 4, 4);
            this->tableLayoutPanel1->Controls->Add(this->NewsaveButton, 3, 11);
            this->tableLayoutPanel1->Controls->Add(this->radioButton2, 4, 11);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 13;
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(482, 332);
            this->tableLayoutPanel1->TabIndex = 45;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label9->Location = System::Drawing::Point(3, 105);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(90, 20);
            this->label9->TabIndex = 19;
            this->label9->Text = L"Halls 1";
            // 
            // halls1
            // 
            this->halls1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->halls1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls1->FormattingEnabled = true;
            this->halls1->Location = System::Drawing::Point(3, 128);
            this->halls1->Name = L"halls1";
            this->halls1->Size = System::Drawing::Size(90, 24);
            this->halls1->TabIndex = 11;
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label10->Location = System::Drawing::Point(99, 105);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(90, 20);
            this->label10->TabIndex = 20;
            this->label10->Text = L"Halls 2";
            // 
            // halls2
            // 
            this->halls2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->halls2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls2->FormattingEnabled = true;
            this->halls2->Location = System::Drawing::Point(99, 128);
            this->halls2->Name = L"halls2";
            this->halls2->Size = System::Drawing::Size(90, 24);
            this->halls2->TabIndex = 12;
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label11->Location = System::Drawing::Point(195, 105);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(90, 20);
            this->label11->TabIndex = 21;
            this->label11->Text = L"Halls 3";
            // 
            // halls3
            // 
            this->halls3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->halls3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls3->FormattingEnabled = true;
            this->halls3->Location = System::Drawing::Point(195, 128);
            this->halls3->Name = L"halls3";
            this->halls3->Size = System::Drawing::Size(90, 24);
            this->halls3->TabIndex = 13;
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label12->Location = System::Drawing::Point(291, 105);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(90, 20);
            this->label12->TabIndex = 22;
            this->label12->Text = L"Halls 4";
            // 
            // halls4
            // 
            this->halls4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->halls4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->halls4->FormattingEnabled = true;
            this->halls4->Location = System::Drawing::Point(291, 128);
            this->halls4->Name = L"halls4";
            this->halls4->Size = System::Drawing::Size(90, 24);
            this->halls4->TabIndex = 14;
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label22->Location = System::Drawing::Point(3, 292);
            this->label22->Name = L"label22";
            this->label22->RightToLeft = System::Windows::Forms::RightToLeft::No;
            this->label22->Size = System::Drawing::Size(90, 40);
            this->label22->TabIndex = 35;
            this->label22->Text = L"Amount of seeds to search through";
            // 
            // amount_of_seeds_to_loop
            // 
            this->amount_of_seeds_to_loop->Dock = System::Windows::Forms::DockStyle::Fill;
            this->amount_of_seeds_to_loop->Increment =
                System::Decimal(gcnew cli::array<System::Int32>(4){100, 0, 0, 0});
            this->amount_of_seeds_to_loop->Location = System::Drawing::Point(99, 295);
            this->amount_of_seeds_to_loop->Maximum = System::Decimal(gcnew cli::array<System::Int32>(4){
                100000000, 0, 0, 0
            });
            this->amount_of_seeds_to_loop->Minimum = System::Decimal(gcnew cli::array<System::Int32>(4){1, 0, 0, 0});
            this->amount_of_seeds_to_loop->Name = L"amount_of_seeds_to_loop";
            this->amount_of_seeds_to_loop->Size = System::Drawing::Size(90, 22);
            this->amount_of_seeds_to_loop->TabIndex = 36;
            this->amount_of_seeds_to_loop->Value = System::Decimal(gcnew cli::array<System::Int32>(4){
                100000000, 0, 0, 0
            });
            // 
            // RandomizeCheckBox
            // 
            this->RandomizeCheckBox->AutoSize = true;
            this->RandomizeCheckBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->RandomizeCheckBox->Location = System::Drawing::Point(291, 295);
            this->RandomizeCheckBox->Name = L"RandomizeCheckBox";
            this->RandomizeCheckBox->Size = System::Drawing::Size(90, 34);
            this->RandomizeCheckBox->TabIndex = 44;
            this->RandomizeCheckBox->Text = L"Randomize";
            this->RandomizeCheckBox->UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button1->Location = System::Drawing::Point(387, 295);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(92, 34);
            this->button1->TabIndex = 43;
            this->button1->Text = L"Reset";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &NewsaveWindow::button1_Click);
            // 
            // outputbox
            // 
            this->outputbox->BackColor = System::Drawing::SystemColors::WindowText;
            this->outputbox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->outputbox->ForeColor = System::Drawing::SystemColors::ControlLight;
            this->outputbox->Location = System::Drawing::Point(387, 108);
            this->outputbox->Name = L"outputbox";
            this->outputbox->ReadOnly = true;
            this->tableLayoutPanel1->SetRowSpan(this->outputbox, 7);
            this->outputbox->Size = System::Drawing::Size(92, 141);
            this->outputbox->TabIndex = 37;
            this->outputbox->Text = L"";
            // 
            // NewsaveButton
            // 
            this->NewsaveButton->AutoSize = true;
            this->NewsaveButton->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NewsaveButton->Location = System::Drawing::Point(291, 255);
            this->NewsaveButton->Name = L"NewsaveButton";
            this->NewsaveButton->Size = System::Drawing::Size(90, 34);
            this->NewsaveButton->TabIndex = 45;
            this->NewsaveButton->TabStop = true;
            this->NewsaveButton->Text = L"Newsave";
            this->NewsaveButton->UseVisualStyleBackColor = true;
            this->NewsaveButton->CheckedChanged += gcnew System::EventHandler(
                this, &NewsaveWindow::NewsaveButton_CheckedChanged);
            // 
            // radioButton2
            // 
            this->radioButton2->AutoSize = true;
            this->radioButton2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->radioButton2->Location = System::Drawing::Point(387, 255);
            this->radioButton2->Name = L"radioButton2";
            this->radioButton2->Size = System::Drawing::Size(92, 34);
            this->radioButton2->TabIndex = 46;
            this->radioButton2->TabStop = true;
            this->radioButton2->Text = L"LoadFile";
            this->radioButton2->UseVisualStyleBackColor = true;
            this->radioButton2->CheckedChanged += gcnew System::EventHandler(
                this, &NewsaveWindow::radioButton2_CheckedChanged);
            // 
            // FileExplorer
            // 
            this->FileExplorer->FileName = L"FileExplorer";
            // 
            // NewsaveWindow
            // 
            this->AcceptButton = this->find_seeds_btn;
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->BackColor = System::Drawing::SystemColors::Menu;
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->ClientSize = System::Drawing::Size(482, 332);
            this->ControlBox = false;
            this->Controls->Add(this->tableLayoutPanel1);
            this->MinimumSize = System::Drawing::Size(500, 350);
            this->Name = L"NewsaveWindow";
            this->ShowIcon = false;
            this->Load += gcnew System::EventHandler(this, &NewsaveWindow::NewsaveWindow_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_of_seeds_to_find))->EndInit();
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_of_seeds_to_loop))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion
    private:
        std::string to_std_string(String^ input)
        {
            const auto chars = static_cast<char*>(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(input).
                ToPointer());
            std::string output(chars);
            Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr(chars));
            return output;
        }

        System::Void find_seeds_btn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            UserInput user_input = get_input_from_user();

            Newsave newsave = Newsave(user_input);
            //split seeds amongst logical cores
            const uint_fast32_t seed_split = (user_input.max_seeds - user_input.min_seeds) / pool.get_thread_amount();

            //give logical core their portion of seeds (not accounting for remainder)

            for (int i = 0; i < pool.get_thread_amount(); i++)
                pool.submit(find_seeds_lambda, newsave, user_input.min_seeds + i * seed_split,
                            user_input.min_seeds + (i + 1) * seed_split);

            //show user new output data
            outputbox->Text = gcnew String(user_input.output_to_string().c_str());
        }

    private:
        /**
         * \brief gets all user input from combo boxes and input fields and puts it in an object
         * \return Output object with all floors (map)
         */
        UserInput get_input_from_user()
        {
            std::vector<Floor> floors = {}; //init floors

            //foreach loop over every "controls" (aka elements on screen)
            for each (Control^ control in tableLayoutPanel1->Controls)
            {
                if (control->GetType() == ComboBox::typeid)
                {
                    auto box = static_cast<ComboBox^>(control);
                    const auto item_index = static_cast<int_fast16_t>(box->SelectedValue); //selected item

                    //filter special combo boxes
                    if (item_index == NOTHING || box == mine1 || box == shoguul || box == shoguul_item1)
                        continue;

                    //add floors
                    floors.push_back(Floor(box->TabIndex, item_index));
                }
            }

            //put everything together in a map, see more at map
            const Map map = Map(static_cast<int>(mine1->SelectedValue), floors,
                                Shoguul(static_cast<int_fast16_t>(shoguul->SelectedValue),
                                        static_cast<int_fast16_t>(shoguul_item1->SelectedValue)));

            count = static_cast<int>(amount_of_seeds_to_find->Value);
            return UserInput(map, count, RandomizeCheckBox->Checked);
        }

    private:
        System::Void NewsaveWindow_Load(System::Object^ sender, System::EventArgs^ e)
        {
            init_dropdowns();
        }

    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            for each (Control^ control in tableLayoutPanel1->Controls)
            {
                if (control->GetType() == ComboBox::typeid)
                {
                    auto box = static_cast<ComboBox^>(control);
                    box->SelectedIndex = 0;
                }
            }
            RandomizeCheckBox->Checked = false;
            outputbox->Text = "";
        }

    private:
        System::Void NewsaveButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
        {
        }

    private:
        System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
        {
        }
    };
}
